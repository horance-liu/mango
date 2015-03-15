#include "mango/core/wire/request/FailingRequest.h"
#include "mango/core/wire/response/FailureResponse.h"

MANGO_NS_BEGIN

WireResponse* FailingRequest::run(Runner&) const
{
    return new FailureResponse;
}

MANGO_NS_END
