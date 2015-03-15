#ifndef HA7AB5AC4_809B_4E82_B04C_09C901436B0A
#define HA7AB5AC4_809B_4E82_B04C_09C901436B0A

#include "mango/core/tag/TagExpr.h"
#include "mango/core/model/Tags.h"

MANGO_NS_BEGIN

struct OrTagExpr : TagExpr
{
    explicit OrTagExpr(const std::string& notation);

    OVERRIDE(bool matches(const Tags& tags) const);

private:
    Tags orTags;
};

MANGO_NS_END

#endif
