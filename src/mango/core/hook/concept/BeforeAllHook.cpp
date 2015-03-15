#include "mango/core/hook/concept/BeforeAllHook.h"
#include "mango/core/runtime/Runtime.h"

MANGO_NS_BEGIN

BeforeAllHook::BeforeAllHook()
{
    REGISTRY(BeforeAllHookRegistry, registry);
    registry.addHook(*this);
}

MANGO_NS_END
