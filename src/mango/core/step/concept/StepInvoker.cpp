#include <mango/core/step/concept/StepInvoker.h>

MANGO_NS_BEGIN

namespace
{
    struct EmptyStepInvoker : StepInvoker
    {
        OVERRIDE(void invokeStep(const InvokeArgs&) const) {}
    };

    static EmptyStepInvoker empty;
}

const StepInvoker& StepInvoker::EMPTY = empty;

MANGO_NS_END
