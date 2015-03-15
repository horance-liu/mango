#include "mango/core/tag/AndTagExpr.h"
#include "mango/core/regex/Regex.h"

MANGO_NS_BEGIN

namespace
{
    Regex& andTagRegex()
    {
        static Regex regex("\\s*\"([^\"]+)\"\\s*(?:,|$)");
        return regex;
    }
}

AndTagExpr::AndTagExpr(const std::string& notation)
{
    RegexMatch match;
    if (!andTagRegex().findAll(notation, match))
    {
        return;
    }

    for (auto submatch : match)
    {
        orTagExprs.emplace_back(submatch.getValue());
    }
}

bool AndTagExpr::matches(const Tags& tags) const
{
    for (auto& tag : orTagExprs)
    {
        if (!tag.matches(tags))
        {
            return false;
        }
    }

    return true;
}

MANGO_NS_END
