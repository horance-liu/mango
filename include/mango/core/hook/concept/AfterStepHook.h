#ifndef HBADCDBDE_62E3_4FED_845D_26F82C3CE21B
#define HBADCDBDE_62E3_4FED_845D_26F82C3CE21B

#include "mango/core/hook/concept/TagableHook.h"

MANGO_NS_BEGIN

struct AfterStepHook : TagableHook
{
    explicit AfterStepHook(const std::string& tag);
};

MANGO_NS_END

#endif
