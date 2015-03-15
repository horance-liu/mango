#include "mango/core/wire/response/FailureResponse.h"
#include "mango/core/wire/response/WireResponseVisitor.h"

MANGO_NS_BEGIN

FailureResponse::FailureResponse(const std::string& msg)
  : msg(msg)
{}

void FailureResponse::accept(WireResponseVisitor& visitor) const
{
    visitor.visitFailureResponse(*this);
}

const std::string& FailureResponse::getMsg() const
{
    return msg;
}

MANGO_NS_END
