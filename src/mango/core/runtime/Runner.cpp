#include <mango/core/runtime/Runner.h>
#include <mango/core/step/concept/MatchingSteps.h>
#include <mango/core/step/concept/StepsFactory.h>
#include <mango/core/step/registry/StepRegistry.h>
#include "infra/std/string.h"

MANGO_NS_BEGIN

Runner::Runner()
  : started(false)
{
}

bool Runner::hasStarted() const
{
    return started;
}

inline void Runner::execBeforeAllHooks()
{
    if (!started)
    {
        started = true;
        ROLE(BeforeAllHookRegistry).execHooks();
    }
}

inline void  Runner::execBeforeHooks(const Tags& tags)
{
    scenario = std::make_shared<Scenario>(tags);
    ROLE(BeforeHookRegistry).execHooks(*scenario);
}

void Runner::beginScenario(const Tags& tags)
{
    execBeforeAllHooks();
    execBeforeHooks(tags);
}

void Runner::endScenario(const Tags& tags)
{
    ROLE(AfterHookRegistry).execHooks(*scenario);
    StepsFactory::stop();
    scenario.reset();
}

MatchingSteps& Runner::stepMatches(const std::string& name, MatchingSteps& matches) const
{
    ROLE(StepRegistry).stepMatches(name, matches);
    return matches;
}

void Runner::invokeStep(const std::string& id, const InvokeArgs& args)
{
    ROLE(AroundStepHookRegistry).execStepChain(*scenario, ROLE(StepRegistry).getStep(id), args);
    ROLE(AfterStepHookRegistry).execHooks(*scenario);
}

std::string Runner::snippetText
     ( const std::string& keyword
     , const std::string& name
     , const std::string& /* multilineArg */) const
{
    std::stringstream snippet;

    snippet << stdext::to_upper(keyword) << "(\"^" << name << "$\") {" << std::endl;
    snippet << "    pending();" << std::endl;
    snippet << "}" << std::endl;

    return snippet.str();
}

MANGO_NS_END
