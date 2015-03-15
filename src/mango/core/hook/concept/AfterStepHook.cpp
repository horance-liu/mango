#include "mango/core/hook/concept/AfterStepHook.h"
#include "mango/core/runtime/Runtime.h"

MANGO_NS_BEGIN

AfterStepHook::AfterStepHook(const std::string& tag)
  : TagableHook(tag)
{
    REGISTRY(AfterStepHookRegistry, registry);
    registry.addHook(*this);
}

MANGO_NS_END
