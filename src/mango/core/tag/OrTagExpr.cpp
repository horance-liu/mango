#include "mango/core/tag/OrTagExpr.h"
#include "mango/core/regex/Regex.h"

MANGO_NS_BEGIN

namespace
{
    Regex& orTagRegex()
    {
        static Regex regex("\\s*@(\\w+)\\s*(?:,|$)");
        return regex;
    }
}

OrTagExpr::OrTagExpr(const std::string& notation)
{
    RegexMatch match;
    if(!orTagRegex().findAll(notation, match))
    {
        return;
    }

    for (auto& submatch : match)
    {
        orTags.addTag(submatch.getValue());
    }
}

bool OrTagExpr::matches(const Tags& tags) const
{
    return orTags.contains(tags);
}

MANGO_NS_END
