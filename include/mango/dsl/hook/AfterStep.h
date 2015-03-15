#ifndef HCF6F618F_5D5C_4F0D_9E66_83080B8EEE58
#define HCF6F618F_5D5C_4F0D_9E66_83080B8EEE58

#include <mango/dsl/hook/HookRegistration.h>
#include "mango/core/hook/concept/AfterStepHook.h"

////////////////////////////////////////////////////////////////////////////////
#define AFTER_STEP_OBJECT(step_name, tag_expr) \
TAGABLE_HOOK(step_name, AfterStepHook, tag_expr)

////////////////////////////////////////////////////////////////////////////////
#define AFTER_STEP(...) AFTER_STEP_OBJECT(HOOK_NAME, ""#__VA_ARGS__)

#endif
