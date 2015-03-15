#include <mango/core/step/concept/StepsFactory.h>

MANGO_NS_BEGIN

std::map<unsigned, void*>& StepsFactory::instances()
{
    static std::map<unsigned, void*> insts;
    return insts;
}

void StepsFactory::stop()
{
    instances().clear();
}

MANGO_NS_END
