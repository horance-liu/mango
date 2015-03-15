#include "mango/core/hook/concept/BeforeHook.h"
#include "mango/core/runtime/Runtime.h"

MANGO_NS_BEGIN

BeforeHook::BeforeHook(const std::string& tag)
  : TagableHook(tag)
{
    REGISTRY(BeforeHookRegistry, registry);
    registry.addHook(*this);
}

MANGO_NS_END
