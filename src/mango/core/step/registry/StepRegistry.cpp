#include <mango/core/step/registry/StepRegistry.h>
#include <mango/core/step/concept/Step.h>
#include <mango/core/step/concept/StepInvoker.h>

MANGO_NS_BEGIN

void StepRegistry::addStep(Step& step)
{
    if (steps.find(step.getId()) == steps.end())
    {
        steps.insert(std::make_pair(step.getId(), &step));
    }
}

void StepRegistry::stepMatches(const std::string& name, MatchingSteps& matches) const
{
    for(auto &entry : steps)
    {
        entry.second->matches(name, matches);
    }
}

const StepInvoker& StepRegistry::getStep(const std::string& id) const
{
    auto step = steps.find(StepId(id));
    return step != steps.end() ? *step->second : StepInvoker::EMPTY;
}

MANGO_NS_END
