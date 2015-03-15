#include <mango/core/step/concept/StepInvoker.h>
#include <mango/core/step/registry/StepRegistry.h>
#include "mango/core/hook/registry/AroundStepHookRegistry.h"
#include "mango/core/hook/concept/AroundStepHook.h"
#include "mango/core/hook/concept/CallableStep.h"

MANGO_NS_BEGIN

void AroundStepHookRegistry::addHook(AroundStepHook& hook)
{
    hooks.push_back(&hook);
}

namespace
{
    struct StepCallChain : private CallableStep
    {
        StepCallChain
            ( const Scenario& scenario
            , const StepInvoker& step
            , const InvokeArgs& args
            , std::vector<AroundStepHook*>& hooks)
            : scenario(scenario)
            , step(step)
            , args(args)
           {
               first = hooks.begin();
               last  = hooks.end();
           }

        void exec()
        {
            if (first == last)
            {
                step.invokeStep(args);
            }
            else
            {
                (*first++)->invokeHook(scenario, this);
            }
        }

    private:
        OVERRIDE(void call())
        {
            exec();
        }

    private:
        const Scenario& scenario;
        const StepInvoker& step;
        const InvokeArgs& args;

        std::vector<AroundStepHook*>::iterator first, last;
    };
}


void AroundStepHookRegistry::execStepChain
    (const Scenario& scenario, const StepInvoker& step, const InvokeArgs& args)
{
    StepCallChain(scenario, step, args, hooks).exec();
}

MANGO_NS_END
