#ifndef H0176D741_C909_4E80_8B81_591F1212468F
#define H0176D741_C909_4E80_8B81_591F1212468F

#include <mango/dsl/hook/HookRegistration.h>
#include "mango/core/hook/concept/AfterAllHook.h"

////////////////////////////////////////////////////////////////////////////////
#define AFTER_ALL_OBJECT(step_name) UNCONDITIONAL_HOOK(step_name, AfterAllHook)

////////////////////////////////////////////////////////////////////////////////
#define AFTER_ALL() AFTER_ALL_OBJECT(HOOK_NAME)

#endif
