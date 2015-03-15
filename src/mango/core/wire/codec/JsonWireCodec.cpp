#include "mango/core/wire/codec/JsonWireCodec.h"
#include "mango/core/wire/response/PendingResponse.h"
#include "mango/core/wire/request/BeginScenarioRequest.h"
#include "mango/core/wire/request/EndScenarioRequest.h"
#include "mango/core/wire/request/StepMatchesRequest.h"
#include "mango/core/wire/request/InvokeRequest.h"
#include "mango/core/wire/request/SnippetTextRequest.h"
#include "mango/core/wire/request/FailingRequest.h"
#include "mango/core/wire/response/WireResponseVisitor.h"

#include <mango/core/model/Table.h>
#include "mango/core/model/Tags.h"

#include "mango/core/wire/response/WireResponse.h"
#include "mango/core/wire/response/FailureResponse.h"
#include "mango/core/wire/response/StepMatchesResponse.h"
#include "mango/core/wire/response/SnippetTextResponse.h"

#include "json_spirit/json_spirit_reader_template.h"
#include "json_spirit/json_spirit_writer_template.h"

#include "infra/base/Singleton.h"

using namespace json_spirit;

MANGO_NS_BEGIN

namespace
{
    DEFINE_ROLE(RequestDecoder)
    {
        ABSTRACT(WireRequest* decode(const mValue& jsonArgs) const);
    };

    Tags& getTags(const mValue& jsonArgs, Tags& tags)
    {
        if (jsonArgs.is_null()) return tags;

        for (auto tag : jsonArgs.get_obj().find("tags")->second.get_array())
        {
            tags.addTag(tag.get_str());
        }

        return tags;
    }

    DEF_SINGLETON(BeginScenarioDecoder) EXTENDS(RequestDecoder)
    {
        OVERRIDE(WireRequest *decode(const mValue& jsonArgs) const)
        {
            Tags tags;
            return new BeginScenarioRequest(getTags(jsonArgs, tags));
        }
    };

    DEF_SINGLETON(EndScenarioDecoder) EXTENDS(RequestDecoder)
    {
        OVERRIDE(WireRequest *decode(const mValue& jsonArgs) const)
        {
            Tags tags;
            return new EndScenarioRequest(getTags(jsonArgs, tags));
        }
    };

    DEF_SINGLETON(StepMatchesDecoder) EXTENDS(RequestDecoder)
    {
        OVERRIDE(WireRequest *decode(const mValue& jsonArgs) const)
        {
            mObject stepMatches(jsonArgs.get_obj());
            return new StepMatchesRequest(stepMatches["name_to_match"].get_str());
        }
    };

    DEF_SINGLETON(InvokeDecoder) EXTENDS(RequestDecoder)
    {
        OVERRIDE(WireRequest *decode(const mValue& jsonArgs) const)
        {
            mObject params(jsonArgs.get_obj());
            return doDecode( params["id"].get_str()
                           , params["args"].get_array());
        }

    private:
        static WireRequest* doDecode(const std::string& id, const mArray& jsonArgs)
        {
            InvokeArgs args;
            fillInvokeArgs(jsonArgs, args);

            return new InvokeRequest(id, args);
        }

        static void fillInvokeArgs(const mArray& jsonArgs, InvokeArgs& args)
        {
            for (auto jsonArg : jsonArgs)
            {
                fillInvokeArg(jsonArg, args);
            }
        }

        static void fillInvokeArg(const mValue& arg, InvokeArgs& args)
        {
            switch(arg.type())
            {
            case str_type:
                args.addArg(arg.get_str());
                break;
            case array_type:
                fillTable(arg.get_array(), args);
                break;
            default: break;
            }
        }

        static void fillTable(const mArray& jsonTable, InvokeArgs& args)
        {
            auto rows = jsonTable.size();
            if (rows == 0) return;

            auto columns = jsonTable[0].get_array().size();

            doFillTable(jsonTable, rows, columns, args);
        }

        static void doFillTable
            ( const mArray& jsonTable
            , size_t rows
            , size_t columns
            , InvokeArgs& args)
        {
            for (auto i = 0lu; i < rows; ++i)
            {
                fillRow(jsonTable[i].get_array(), columns, args);
            }
        }

        static void fillRow(const mArray& jsonRow, size_t columns, InvokeArgs& args)
        {
            Table::row_type row;

            for (auto j = 0lu; j < columns; ++j)
            {
                row.push_back(jsonRow[j].get_str());
            }

            args.addRow(std::move(row));
        }
    };

    DEF_SINGLETON(SnippetTextDecoder) EXTENDS(RequestDecoder)
    {
        OVERRIDE(WireRequest *decode(const mValue& jsonArgs) const)
        {
            mObject snippet(jsonArgs.get_obj());

            return new SnippetTextRequest
                    ( snippet["step_keyword"].get_str()
                    , snippet["step_name"].get_str()
                    , snippet["multiline_arg_class"].get_str());
        }
    };

#define WIRE_DECODER(decoder) &decoder::getInstance()

    std::map<std::string, RequestDecoder*> decoders {
        {"begin_scenario", WIRE_DECODER(BeginScenarioDecoder)},
        {"end_scenario",   WIRE_DECODER(EndScenarioDecoder)},
        {"step_matches",   WIRE_DECODER(StepMatchesDecoder)},
        {"invoke",         WIRE_DECODER(InvokeDecoder)},
        {"snippet_text",   WIRE_DECODER(SnippetTextDecoder)},
    };

    mValue& getJsonArgs(mArray& jsonReq)
    {
        static mValue nilValue;
        return jsonReq.size() > 1 ? jsonReq[1] : nilValue;
    }

#define ASSERT_JSON_TRUE(expr)                  \
    do {                                        \
        if (!(expr)) return new FailingRequest; \
    } while (0)

    WireRequest* doDecode(mArray& jsonReq)
    {
        ASSERT_JSON_TRUE(jsonReq.size() != 0);

        auto decoder = decoders[jsonReq[0].get_str()];
        ASSERT_JSON_TRUE(decoder != nullptr);

        return decoder->decode(getJsonArgs(jsonReq));
    }
}

WireRequest* JsonWireCodec::decode(const std::string& request) const
{
    std::istringstream is(request);
    mValue json;

    read_stream(is, json);

    return doDecode(json.get_array());
}

namespace
{
    struct WireResponseEncoder : private WireResponseVisitor
    {
        WireResponseEncoder()
        {
            jsonOutput.clear();
        }

        std::string encode(WireResponse& response)
        {
            response.accept(*this);
            const mValue value(jsonOutput);
            return write_string(value, false);
        }

    private:
        OVERRIDE(void visitSuccessResponse(const SuccessResponse&))
        {
            success();
        }

        OVERRIDE(void visitFailureResponse(const FailureResponse& response))
        {
            mObject detailObject;

            writeIfNotEmpty("message", response.getMsg(), detailObject);
            writeFailDetails(detailObject);
        }

        OVERRIDE(void visitPendingResponse(const PendingResponse& response))
        {
            mValue jsonReponse(response.getMsg());
            output("pending", &jsonReponse);
        }

        OVERRIDE(void visitStepMatchesResponse(const StepMatchesResponse& response))
        {
            mArray jsonMatches;
            for(auto& stepMatch : response.getMatchingSteps())
            {
                writeStepMatch(stepMatch, jsonMatches);
            }
            mValue jsonReponse(jsonMatches);
            output("success", &jsonReponse);
        }

        OVERRIDE(void visitSnippetTextResponse(const SnippetTextResponse& response))
        {
            mValue jsonReponse(response.getStepSnippet());
            success(&jsonReponse);
        }

    private:
        void writeStepMatch(const MatchingStep& step, mArray& jsonMatches)
        {
            mObject jsonM;

            writeIfNotEmpty("id", step.id, jsonM);
            writeArgs(step, jsonM);

            writeIfNotEmpty("source", step.source, jsonM);
            writeIfNotEmpty("regexp", step.regexp, jsonM);

            jsonMatches.push_back(jsonM);
        }

        void writeIfNotEmpty(const std::string& key, const std::string& value, mObject& jsonM)
        {
            if (!value.empty())
            {
                jsonM[key] = value;
            }
        }

        void writeArgs(const MatchingStep& step, mObject& jsonM)
        {
            mArray jsonArgs;
            for(auto& ma : step.args)
            {
                mObject jsonMa;
                jsonMa["val"] = ma.getValue();
                jsonMa["pos"] = ma.getPosition();
                jsonArgs.push_back(jsonMa);
            }
            jsonM["args"] = jsonArgs;
        }

        void writeFailDetails(const mObject& detailObject)
        {
            if (detailObject.empty())
            {
                fail();
            }
            else
            {
                const mValue detail(detailObject);
                fail(&detail);
            }
        }

    private:
        void success(const mValue *detail = 0)
        {
            output("success", detail);
        }

        void fail(const mValue *detail = 0)
        {
            output("fail", detail);
        }

        void output(const char* type, const mValue* detail = 0)
        {
            jsonOutput.push_back(type);

            if (detail != 0 && !detail->is_null())
            {
                jsonOutput.push_back(*detail);
            }
        }

    private:
        mArray jsonOutput;
    };
}

std::string JsonWireCodec::encode(WireResponse& response) const
{
    return WireResponseEncoder().encode(response);
}

MANGO_NS_END
