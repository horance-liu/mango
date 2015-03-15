#ifndef HAAADE972_898C_4D75_95D0_A2EA61673DEF
#define HAAADE972_898C_4D75_95D0_A2EA61673DEF

#include "mango/base/mango.h"
#include <vector>

MANGO_NS_BEGIN

struct TagableHook;
struct Scenario;

struct TagableHookRegistry
{
    void addHook(TagableHook& hook);
    void execHooks(const Scenario& scenario);

private:
    std::vector<TagableHook*> hooks;
};

MANGO_NS_END

#endif
