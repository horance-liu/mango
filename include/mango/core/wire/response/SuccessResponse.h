#ifndef HF36D9A90_A160_49A3_AAA4_786F49088C10
#define HF36D9A90_A160_49A3_AAA4_786F49088C10

#include "mango/core/wire/response/WireResponse.h"

MANGO_NS_BEGIN

struct SuccessResponse : WireResponse
{
    OVERRIDE(void accept(WireResponseVisitor&) const);
};

MANGO_NS_END

#endif
