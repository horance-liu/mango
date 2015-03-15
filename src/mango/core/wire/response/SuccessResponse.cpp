#include "mango/core/wire/response/SuccessResponse.h"
#include "mango/core/wire/response/WireResponseVisitor.h"

MANGO_NS_BEGIN

void SuccessResponse::accept(WireResponseVisitor& visitor) const
{
    visitor.visitSuccessResponse(*this);
}

MANGO_NS_END
