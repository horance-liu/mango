#include "mango/core/hook/concept/AfterHook.h"
#include "mango/core/runtime/Runtime.h"

MANGO_NS_BEGIN

AfterHook::AfterHook(const std::string& tag)
  : TagableHook(tag)
{
    REGISTRY(AfterHookRegistry, registry);
    registry.addHook(*this);
}

MANGO_NS_END
