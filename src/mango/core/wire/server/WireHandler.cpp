#include "mango/core/wire/server/WireHandler.h"
#include "mango/core/wire/request/WireRequest.h"
#include "mango/core/wire/response/WireResponse.h"
#include "mango/core/wire/codec/WireCodec.h"
#include <memory>

MANGO_NS_BEGIN

std::string WireHandler::handle(const std::string& msg) const
{
    try {
        std::unique_ptr<WireRequest> req(ROLE(WireCodec).decode(msg));
        std::unique_ptr<WireResponse> rsp(req->run(ROLE(Runner)));
        return ROLE(WireCodec).encode(*rsp);
    } catch (...) {
        return "[\"fail\"]";
    }
}

MANGO_NS_END
