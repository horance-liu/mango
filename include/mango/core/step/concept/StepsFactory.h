#ifndef H0CA46078_A790_4336_AB97_301191088474
#define H0CA46078_A790_4336_AB97_301191088474

#include "mango/base/mango.h"
#include <map>

MANGO_NS_BEGIN

struct StepsFactory
{
    static void stop();

    template <typename StepDefinition>
    static StepDefinition& create()
    {
        auto id = StepDefinition::getId();
        auto found = instances().find(id);

        if (found == instances().end())
        {
            instances().insert(std::make_pair(id, new StepDefinition));
        }

        return *static_cast<StepDefinition*>(instances()[id]);
    }

private:
    static std::map<unsigned, void*>& instances();
};

MANGO_NS_END

#endif
