#ifndef H4FB027AF_C34F_4164_AE91_0A8A924F7DC9
#define H4FB027AF_C34F_4164_AE91_0A8A924F7DC9

#include "mango/core/hook/registry/TagableHookRegistry.h"
#include "mango/core/hook/registry/UnconditionalHookRegistry.h"
#include "mango/core/hook/registry/AroundStepHookRegistry.h"

MANGO_NS_BEGIN

using BeforeHookRegistry = TagableHookRegistry;
using AfterHookRegistry = TagableHookRegistry;
using AfterStepHookRegistry = TagableHookRegistry;

using BeforeAllHookRegistry = UnconditionalHookRegistry;
using AfterAllHookRegistry = UnconditionalHookRegistry;

MANGO_NS_END

#endif
