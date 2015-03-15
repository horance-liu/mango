#ifndef H3A6E97D9_E5A6_4F47_8A8A_EB0CE0249166
#define H3A6E97D9_E5A6_4F47_8A8A_EB0CE0249166

#include "mango/infra/dci/Role.h"
#include "mango/core/hook/registry/HookRegistries.h"

MANGO_NS_BEGIN

struct Runner;
struct StepRegistry;

DEFINE_ROLE(Runtime)
{
    static Runtime& runtime();

    ABSTRACT(int run(int argc, char **argv));

    HAS_ROLE(Runner);

    HAS_ROLE(BeforeHookRegistry);
    HAS_ROLE(AfterHookRegistry);

    HAS_ROLE(AfterStepHookRegistry);
    HAS_ROLE(AroundStepHookRegistry);

    HAS_ROLE(BeforeAllHookRegistry);
    HAS_ROLE(AfterAllHookRegistry);

    HAS_ROLE(StepRegistry);
};

#define REGISTRY(type, name) type& name = Runtime::runtime().ROLE(type)

MANGO_NS_END

#endif
