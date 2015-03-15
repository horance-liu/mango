#ifndef H91A4EFCF_7E56_4154_AFA2_6442B2ACE600
#define H91A4EFCF_7E56_4154_AFA2_6442B2ACE600

#include "mango/core/tag/OrTagExpr.h"
#include <vector>

MANGO_NS_BEGIN

struct AndTagExpr : TagExpr
{
    explicit AndTagExpr(const std::string& notation);

    OVERRIDE(bool matches(const Tags& tags) const);

private:
    std::vector<OrTagExpr> orTagExprs;
};

MANGO_NS_END

#endif
