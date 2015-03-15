#ifndef H18BEB51D_B693_45D7_9493_6386E4BD6437
#define H18BEB51D_B693_45D7_9493_6386E4BD6437

#include <mango/dsl/hook/HookRegistration.h>
#include "mango/core/hook/concept/BeforeAllHook.h"

////////////////////////////////////////////////////////////////////////////////
#define BEFORE_ALL_OBJECT(step_name) UNCONDITIONAL_HOOK(step_name, BeforeAllHook)

////////////////////////////////////////////////////////////////////////////////
#define BEFORE_ALL() BEFORE_ALL_OBJECT(HOOK_NAME)


#endif
