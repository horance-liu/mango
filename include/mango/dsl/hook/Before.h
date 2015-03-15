#ifndef H07FFEE02_6776_44B2_9856_7EF500414195
#define H07FFEE02_6776_44B2_9856_7EF500414195

#include <mango/dsl/hook/HookRegistration.h>
#include "mango/core/hook/concept/BeforeHook.h"

////////////////////////////////////////////////////////////////////////////////
#define BEFORE_OBJECT(step_name, tag_expr) \
TAGABLE_HOOK(step_name, BeforeHook, tag_expr)

////////////////////////////////////////////////////////////////////////////////
#define BEFORE(...) BEFORE_OBJECT(HOOK_NAME, "" #__VA_ARGS__)

#endif
