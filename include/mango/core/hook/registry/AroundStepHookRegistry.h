#ifndef H56C326F3_4860_4DF5_A255_48C19DBAEF1B
#define H56C326F3_4860_4DF5_A255_48C19DBAEF1B

#include "mango/base/mango.h"
#include <vector>

MANGO_NS_BEGIN

struct AroundStepHook;
struct Scenario;
struct StepInvoker;
struct InvokeArgs;

struct AroundStepHookRegistry
{
    void addHook(AroundStepHook&);
    void execStepChain(const Scenario& scenario, const StepInvoker& step, const InvokeArgs& args);

private:
    std::vector<AroundStepHook*> hooks;
};

MANGO_NS_END

#endif
