#include <mango/core/wire/response/PendingResponse.h>
#include "mango/core/wire/response/WireResponseVisitor.h"

MANGO_NS_BEGIN

PendingResponse::PendingResponse(const std::string& msg)
  : msg(msg)
{}


void PendingResponse::accept(WireResponseVisitor& visitor) const
{
    visitor.visitPendingResponse(*this);
}

const std::string& PendingResponse::getMsg() const
{
    return msg;
}

MANGO_NS_END
