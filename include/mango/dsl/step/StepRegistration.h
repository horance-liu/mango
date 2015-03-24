#ifndef HC0A7BA6C_4704_426A_BFBE_068108FFE0D1
#define HC0A7BA6C_4704_426A_BFBE_068108FFE0D1

#include <l0-infra/std/Symbol.h>
#include "l0-infra/std/SourceFile.h"

#include "mango/core/step/concept/GenericSteps.h"
#include "mango/core/step/concept/GenericStep.h"
#include "mango/core/step/concept/StepsRegistry.h"
#include "mango/core/model/InvokeArgs.h"

////////////////////////////////////////////////////////////////////////////////
#define __UNIQUE_NAME(prefix, unique_id) JOIN(prefix, unique_id)

////////////////////////////////////////////////////////////////////////////////
#define __STEPS_NAME(prefix, unique_id)          __UNIQUE_NAME(prefix, unique_id)
#define __STEPS_REGISTRY_NAME(prefix, unique_id) __UNIQUE_NAME(prefix##Registry, unique_id)
#define __STEPS_REGISTRY_VAR(prefix, unique_id)  __STEPS_REGISTRY_NAME(var_##prefix, unique_id)

////////////////////////////////////////////////////////////////////////////////
#define __DEF_STPES(prefix, unique_id)                                  \
    struct __STEPS_NAME(prefix, unique_id);                             \
    static struct __STEPS_REGISTRY_NAME(prefix, unique_id)              \
    {                                                                   \
        __STEPS_REGISTRY_NAME(prefix, unique_id)()                      \
        {                                                               \
            ::mango::StepsRegistry::getInstance()                       \
                 .registerSteps<__STEPS_NAME(prefix, unique_id)>();     \
        }                                                               \
    } __STEPS_REGISTRY_VAR(prefix, unique_id);                          \
    struct __UNIQUE_NAME(prefix, unique_id) :                           \
    ::mango::GenericSteps<unique_id, __UNIQUE_NAME(prefix, unique_id)>

////////////////////////////////////////////////////////////////////////////////
#define __STEP_NAME(unique_id) __UNIQUE_NAME(def_Step, unique_id)

////////////////////////////////////////////////////////////////////////////////
#define __DEF_STEP(matcher, unique_id)                                         \
::mango::GenericStep<unique_id, steps_type> __UNIQUE_NAME(var_Step, unique_id) \
    {matcher, SHORT_FILE(), &steps_type::__STEP_NAME(unique_id)};             \
    void __STEP_NAME(unique_id)(const ::mango::InvokeArgs& args)

////////////////////////////////////////////////////////////////////////////////
#define __STEP(matcher) __DEF_STEP(matcher, __COUNTER__)

#endif
