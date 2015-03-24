#ifndef HF684758E_DF21_4935_A12B_C08437B519B1
#define HF684758E_DF21_4935_A12B_C08437B519B1

#include "l0-infra/base/Singleton.h"
#include "mango/core/step/concept/Steps.h"
#include <vector>

MANGO_NS_BEGIN

struct Steps;

DEF_SINGLETON(StepsRegistry)
{
    ~StepsRegistry();

    template <typename Steps>
    void registerSteps()
    {
        registry.push_back(new Steps);
    }

private:
    std::vector<Steps*> registry;
};

MANGO_NS_END

#endif
