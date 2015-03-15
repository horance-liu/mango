#include "mango/core/hook/concept/AfterAllHook.h"
#include "mango/core/runtime/Runtime.h"

MANGO_NS_BEGIN

AfterAllHook::AfterAllHook()
{
    REGISTRY(AfterAllHookRegistry, registry);
    registry.addHook(*this);
}

MANGO_NS_END
