#ifndef HB24D0A50_B5F1_46F4_8F7E_75BF97010C11
#define HB24D0A50_B5F1_46F4_8F7E_75BF97010C11

#include <mango/core/step/concept/MatchingSteps.h>
#include <mango/core/step/concept/StepId.h>
#include <map>

MANGO_NS_BEGIN

struct Step;
struct StepInvoker;

struct StepRegistry
{
    void addStep(Step& step);

    void stepMatches(const std::string& name, MatchingSteps& matches) const;
    const StepInvoker& getStep(const std::string& id) const;

private:
    std::map<StepId, Step*> steps;
};

MANGO_NS_END

#endif
