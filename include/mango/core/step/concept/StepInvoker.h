#ifndef H8CEF5425_905F_4AED_AED9_5AFCE501370E
#define H8CEF5425_905F_4AED_AED9_5AFCE501370E

#include <mango/infra/dci/Role.h>
#include <mango/core/base/mango.h>

MANGO_NS_BEGIN

struct InvokeArgs;

DEFINE_ROLE(StepInvoker)
{
    ABSTRACT(void invokeStep(const InvokeArgs& args) const);

    static const StepInvoker& EMPTY;
};

MANGO_NS_END

#endif
