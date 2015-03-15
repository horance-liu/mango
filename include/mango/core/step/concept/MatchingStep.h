#ifndef H2485AA8F_64D0_48D9_8D7C_1472D1616E36
#define H2485AA8F_64D0_48D9_8D7C_1472D1616E36

#include "mango/core/regex/RegexMatch.h"

MANGO_NS_BEGIN

struct MatchingStep
{
    MatchingStep( const std::string& id
             , const std::string& regex
             , const std::string& source
             , const RegexMatch& args);

    std::string id;
    std::string source;
    std::string regexp;
    RegexMatch args;
};

MANGO_NS_END

#endif
