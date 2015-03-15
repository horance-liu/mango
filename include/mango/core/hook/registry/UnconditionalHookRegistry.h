#ifndef H1A975F99_B6B5_4C0D_BAA7_F004E580F49E
#define H1A975F99_B6B5_4C0D_BAA7_F004E580F49E

#include "mango/base/mango.h"
#include <vector>

MANGO_NS_BEGIN

struct UnconditionalHook;

struct UnconditionalHookRegistry
{
    void addHook(UnconditionalHook& hook);
    void execHooks();

private:
    std::vector<UnconditionalHook*> hooks;
};

MANGO_NS_END

#endif
