#include "mango/core/hook/concept/AroundStepHook.h"
#include "mango/core/hook/concept/CallableStep.h"
#include "mango/core/runtime/Runtime.h"

MANGO_NS_BEGIN

AroundStepHook::AroundStepHook(const std::string& tag)
  : TagableHook(tag), step(nullptr)
{
    REGISTRY(AroundStepHookRegistry, registry);
    registry.addHook(*this);
}

void AroundStepHook::invokeHook(const Scenario& scenario, CallableStep* step)
{
    this->step = step;
    TagableHook::invokeHook(scenario);
}

void AroundStepHook::skipHook()
{
    step->call();
}

MANGO_NS_END
