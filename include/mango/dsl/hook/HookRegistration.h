#ifndef HDD3AF611_DD45_4B48_9BD5_5FB5BEB2751A
#define HDD3AF611_DD45_4B48_9BD5_5FB5BEB2751A

#include <mango/infra/base/Symbol.h>
#include "mango/core/base/mango.h"

////////////////////////////////////////////////////////////////////////////////
#define HOOK_NAME UNIQUE_NAME(HookObject)

////////////////////////////////////////////////////////////////////////////////
#define TAGABLE_HOOK(class_name, parent_class, tag_expr) \
struct class_name : MANGO_NS::parent_class       \
{                                                \
    using MANGO_NS::parent_class::parent_class;  \
                                                 \
private:                                         \
    OVERRIDE(void invoke());                     \
};                                               \
const class_name var##class_name(tag_expr);      \
void class_name::invoke()

////////////////////////////////////////////////////////////////////////////////
#define UNCONDITIONAL_HOOK(class_name, parent_class) \
struct class_name : MANGO_NS::parent_class       \
{                                                \
    class_name() {}                              \
                                                 \
private:                                         \
    OVERRIDE(void invoke());                     \
};                                               \
const class_name var##class_name;                \
void class_name::invoke()

#endif
