#ifndef H916A4A7A_E79D_4337_9862_3DAE026A816A
#define H916A4A7A_E79D_4337_9862_3DAE026A816A

#include <mango/core/except/PendingStepException.h>
#include <mango/core/step/concept/Steps.h>

MANGO_NS_BEGIN

template <unsigned ID, typename STEPS>
struct GenericSteps : Steps
{
    using steps_type = STEPS;

    static unsigned getId()
    {
        return ID;
    }

    void pending(const std::string& desc)
    {
        throw PendingStepException(desc);
    }
};

MANGO_NS_END

#endif
