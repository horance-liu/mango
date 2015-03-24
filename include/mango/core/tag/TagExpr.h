#ifndef H4C07CBCC_45B0_4C05_93AA_25E8AFBD42C0
#define H4C07CBCC_45B0_4C05_93AA_25E8AFBD42C0

#include "mango/core/base/mango.h"
#include "l0-infra/base/Role.h"

MANGO_NS_BEGIN

struct Tags;

DEFINE_ROLE(TagExpr)
{
    ABSTRACT(bool matches(const Tags& tags) const);
};

MANGO_NS_END

#endif
