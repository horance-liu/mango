#ifndef H175416A9_5782_4CF5_BF88_6F75D4C40D50
#define H175416A9_5782_4CF5_BF88_6F75D4C40D50

#include "mango/core/hook/concept/TagableHook.h"
#include "mango/core/hook/concept/CallableStep.h"

MANGO_NS_BEGIN

struct AroundStepHook : private TagableHook
{
    AroundStepHook(const std::string& tag);

    void invokeHook(const Scenario& scenario, CallableStep* step);

private:
    OVERRIDE(void skipHook());

protected:
    CallableStep* step;
};

MANGO_NS_END

#endif
