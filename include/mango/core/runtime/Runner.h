#ifndef H9DC02549_17F2_475B_9D23_F0BA379189D0
#define H9DC02549_17F2_475B_9D23_F0BA379189D0

#include "mango/infra/dci/Role.h"
#include "mango/core/step/concept/MatchingSteps.h"
#include "mango/core/hook/registry/HookRegistries.h"
#include "mango/core/model/Scenario.h"
#include <string>
#include <memory>

MANGO_NS_BEGIN

struct Scenario;
struct Tags;
struct InvokeArgs;
struct StepRegistry;

DEFINE_ROLE(Runner)
{
    Runner();

    bool hasStarted() const;

    void beginScenario(const Tags& tags);
    void endScenario(const Tags& tags);

    MatchingSteps& stepMatches(const std::string& name, MatchingSteps& matches) const;
    void invokeStep(const std::string& id, const InvokeArgs& args);

    std::string snippetText
         ( const std::string& keyword
         , const std::string& name
         , const std::string& multilineArgClass) const;

private:
    void execBeforeAllHooks();
    void execBeforeHooks(const Tags&);

private:
    bool started;
    std::shared_ptr<Scenario> scenario;

private:
    USE_ROLE(BeforeAllHookRegistry);
    USE_ROLE(AfterAllHookRegistry);

    USE_ROLE(BeforeHookRegistry);
    USE_ROLE(AfterHookRegistry);

    USE_ROLE(AroundStepHookRegistry);
    USE_ROLE(AfterStepHookRegistry);

    USE_ROLE(StepRegistry);
};

MANGO_NS_END

#endif
