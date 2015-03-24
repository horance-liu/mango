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

#include "json/json.h"

#include "l0-infra/base/Singleton.h"

using namespace Json;

MANGO_NS_BEGIN

namespace
{
    DEFINE_ROLE(RequestDecoder)
    {
        ABSTRACT(WireRequest* decode(const Value& jsonArgs) const);
    };

    Tags& getTags(const Value& jsonArgs, Tags& tags)
    {
        if (jsonArgs.isNull()) return tags;

        for (auto& tag : jsonArgs["tags"])
        {
            tags.addTag(tag.asString());
        }

        return tags;
    }

    DEF_SINGLETON(BeginScenarioDecoder) EXTENDS(RequestDecoder)
    {
        OVERRIDE(WireRequest *decode(const Value& jsonArgs) const)
        {
            Tags tags;
            return new BeginScenarioRequest(getTags(jsonArgs, tags));
        }
    };

    DEF_SINGLETON(EndScenarioDecoder) EXTENDS(RequestDecoder)
    {
        OVERRIDE(WireRequest *decode(const Value& jsonArgs) const)
        {
            Tags tags;
            return new EndScenarioRequest(getTags(jsonArgs, tags));
        }
    };

    DEF_SINGLETON(StepMatchesDecoder) EXTENDS(RequestDecoder)
    {
        OVERRIDE(WireRequest *decode(const Value& jsonArgs) const)
        {
            return new StepMatchesRequest(jsonArgs["name_to_match"].asString());
        }
    };

    DEF_SINGLETON(InvokeDecoder) EXTENDS(RequestDecoder)
    {
        OVERRIDE(WireRequest *decode(const Value& jsonArgs) const)
        {
            return doDecode( jsonArgs["id"].asString()
                           , jsonArgs["args"]);
        }

    private:
        static WireRequest* doDecode(const std::string& id, const Value& jsonArgs)
        {
            InvokeArgs args;

            for (auto& jsonArg : jsonArgs)
            {
                fillInvokeArg(jsonArg, args);
            }

            return new InvokeRequest(id, args);
        }

        static void fillInvokeArg(const Value& arg, InvokeArgs& args)
        {
            switch(arg.type())
            {
            case stringValue:
                args.addArg(arg.asString());
                break;
            case arrayValue:
                fillTable(arg, args);
                break;
            default: break;
            }
        }

        static void fillTable(const Value& jsonTable, InvokeArgs& args)
        {
            for (auto& rowJson :  jsonTable)
            {
                fillRow(rowJson, args);
            }
        }

        static void fillRow(const Value& jsonRow, InvokeArgs& args)
        {
            Table::row_type row;

            for (auto& value : jsonRow)
            {
                row.push_back(value.asString());
            }

            args.addRow(std::move(row));
        }
    };

    DEF_SINGLETON(SnippetTextDecoder) EXTENDS(RequestDecoder)
    {
        OVERRIDE(WireRequest *decode(const Value& jsonArgs) const)
        {
            return new SnippetTextRequest
                    ( jsonArgs["step_keyword"].asString()
                    , jsonArgs["step_name"].asString()
                    , jsonArgs["multiline_arg_class"].asString());
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

    const Value& getJsonArgs(Value& jsonReq)
    {
        return jsonReq.size() > 1 ? jsonReq[1] : Value::null;
    }

#define ASSERT_JSON_TRUE(expr)                  \
    do {                                        \
        if (!(expr)) return new FailingRequest; \
    } while (0)

    WireRequest* doDecode(Value& jsonReq)
    {
        ASSERT_JSON_TRUE(jsonReq.size() != 0);

        auto decoder = decoders[jsonReq[0].asString()];
        ASSERT_JSON_TRUE(decoder != nullptr);

        return decoder->decode(getJsonArgs(jsonReq));
    }
}

WireRequest* JsonWireCodec::decode(const std::string& request) const
{
    std::istringstream is(request);
    Value json;

    Reader reader;

    if (!reader.parse(is, json, false))
    {
        return nullptr;
    }

    return doDecode(json);
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
            return stdext::rtrim(writer.write(jsonOutput));
        }

    private:
        OVERRIDE(void visitSuccessResponse(const SuccessResponse&))
        {
            success();
        }

        OVERRIDE(void visitFailureResponse(const FailureResponse& response))
        {
            Value detailObject;

            writeIfNotEmpty("message", response.getMsg(), detailObject);
            writeFailDetails(detailObject);
        }

        OVERRIDE(void visitPendingResponse(const PendingResponse& response))
        {
            Value jsonReponse(response.getMsg());
            output("pending", &jsonReponse);
        }

        OVERRIDE(void visitStepMatchesResponse(const StepMatchesResponse& response))
        {
            Value jsonMatches;
            for(auto& stepMatch : response.getMatchingSteps())
            {
                writeStepMatch(stepMatch, jsonMatches);
            }
            output("success", &jsonMatches);
        }

        OVERRIDE(void visitSnippetTextResponse(const SnippetTextResponse& response))
        {
            Value jsonReponse(response.getStepSnippet());
            success(&jsonReponse);
        }

    private:
        void writeStepMatch(const MatchingStep& step, Value& jsonMatches)
        {
            Value jsonM;

            writeIfNotEmpty("id", step.id, jsonM);
            writeArgs(step, jsonM);

            writeIfNotEmpty("source", step.source, jsonM);
            writeIfNotEmpty("regexp", step.regexp, jsonM);

            jsonMatches.append(jsonM);
        }

        void writeIfNotEmpty(const std::string& key, const std::string& value, Value& jsonM)
        {
            if (!value.empty())
            {
                jsonM[key] = value;
            }
        }

        void writeArgs(const MatchingStep& step, Value& jsonM)
        {
            Value jsonArgs(arrayValue);
            for(auto& ma : step.args)
            {
                Value jsonMa;
                jsonMa["val"] = ma.getValue();
                jsonMa["pos"] = ma.getPosition();
                jsonArgs.append(jsonMa);
            }
            jsonM["args"] = jsonArgs;
        }

        void writeFailDetails(const Value& detailObject)
        {
            detailObject.empty() ? fail() : fail(&detailObject);
        }

    private:
        void success(const Value *detail = 0)
        {
            output("success", detail);
        }

        void fail(const Value *detail = 0)
        {
            output("fail", detail);
        }

        void output(const char* type, const Value* detail = 0)
        {
            jsonOutput.append(type);

            if (detail != 0 && !detail->isNull())
            {
                jsonOutput.append(*detail);
            }
        }

    private:
        Value jsonOutput;
        FastWriter writer;
    };
}

std::string JsonWireCodec::encode(WireResponse& response) const
{
    return WireResponseEncoder().encode(response);
}

MANGO_NS_END
