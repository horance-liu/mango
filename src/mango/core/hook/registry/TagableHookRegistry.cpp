#include "mango/core/hook/registry/TagableHookRegistry.h"
#include "mango/core/hook/concept/TagableHook.h"

MANGO_NS_BEGIN

void TagableHookRegistry::addHook(TagableHook& hook)
{
    hooks.push_back(&hook);
}

void TagableHookRegistry::execHooks(const Scenario& scenario)
{
    for (auto hook : hooks)
    {
        hook->invokeHook(scenario);
    }
}

MANGO_NS_END
