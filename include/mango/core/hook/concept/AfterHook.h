#ifndef H88C94836_B4C3_4ADD_9C2C_AC182BFE1284
#define H88C94836_B4C3_4ADD_9C2C_AC182BFE1284

#include "mango/core/hook/concept/TagableHook.h"

MANGO_NS_BEGIN

struct AfterHook : TagableHook
{
    explicit AfterHook(const std::string& tag);
};

MANGO_NS_END

#endif
