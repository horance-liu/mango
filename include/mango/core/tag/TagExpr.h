#ifndef H4C07CBCC_45B0_4C05_93AA_25E8AFBD42C0
#define H4C07CBCC_45B0_4C05_93AA_25E8AFBD42C0

#include "mango/base/mango.h"
#include "infra/dci/Role.h"

MANGO_NS_BEGIN

struct Tags;

DEFINE_ROLE(TagExpr)
{
    ABSTRACT(bool matches(const Tags& tags) const);
};

MANGO_NS_END

#endif
