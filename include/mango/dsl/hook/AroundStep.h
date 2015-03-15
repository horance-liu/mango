#ifndef H6F6E39AC_5068_44A5_8C80_EDA3F53AD8FB
#define H6F6E39AC_5068_44A5_8C80_EDA3F53AD8FB

#include <mango/dsl/hook/HookRegistration.h>
#include "mango/core/hook/concept/AroundStepHook.h"

////////////////////////////////////////////////////////////////////////////////
#define AROUND_STEP_OBJECT(step_name, tag_expr) \
TAGABLE_HOOK(step_name, AroundStepHook, tag_expr)

////////////////////////////////////////////////////////////////////////////////
#define AROUND_STEP(...) AROUND_STEP_OBJECT(HOOK_NAME, ""#__VA_ARGS__)

#endif
