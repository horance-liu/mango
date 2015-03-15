#include "mango/core/hook/registry/UnconditionalHookRegistry.h"
#include "mango/core/hook/concept/UnconditionalHook.h"

MANGO_NS_BEGIN

void UnconditionalHookRegistry::addHook(UnconditionalHook& hook)
{
    hooks.push_back(&hook);
}

void UnconditionalHookRegistry::execHooks()
{
    for (auto hook : hooks)
    {
        hook->invoke();
    }
}

MANGO_NS_END
