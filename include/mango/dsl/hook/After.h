#ifndef HD1373361_E9D2_49F1_BA18_72D9F24CEF19
#define HD1373361_E9D2_49F1_BA18_72D9F24CEF19

#include <mango/dsl/hook/HookRegistration.h>
#include "mango/core/hook/concept/AfterHook.h"

////////////////////////////////////////////////////////////////////////////////
#define AFTER_OBJECT(step_name, tag_expr) \
TAGABLE_HOOK(step_name, AfterHook, tag_expr)

////////////////////////////////////////////////////////////////////////////////
#define AFTER(...) AFTER_OBJECT(HOOK_NAME, ""#__VA_ARGS__)

#endif
