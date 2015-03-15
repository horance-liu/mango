#include <mango/core/step/concept/MatchingStep.h>

MANGO_NS_BEGIN

MatchingStep::MatchingStep
    ( const std::string& id
    , const std::string& regexp
    , const std::string& source
    , const RegexMatch& match)
    : id(id), regexp(regexp), source(source), args(match)
{}

MANGO_NS_END
