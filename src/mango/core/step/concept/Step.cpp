#include <mango/core/step/concept/Step.h>
#include <mango/core/step/concept/MatchingStep.h>
#include <mango/core/step/concept/MatchingSteps.h>

MANGO_NS_BEGIN

Step::Step(const StepId& id, const std::string& matcher, const std::string& source)
    : id(id), regex(matcher), source(source)
{}

const StepId& Step::getId() const
{
    return id;
}

void Step::matches(const std::string& desc, MatchingSteps& matches) const
{
    RegexMatch match;
    if (regex.find(desc, match))
    {
        matches.emplace_back(id.toString(), regex.str(), source, match);
    }
}

MANGO_NS_END
