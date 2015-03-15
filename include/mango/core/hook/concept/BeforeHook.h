#ifndef H9A90F86E_7C4B_4FB7_8B74_A85B34E32DE7
#define H9A90F86E_7C4B_4FB7_8B74_A85B34E32DE7

#include "mango/core/hook/concept/TagableHook.h"

MANGO_NS_BEGIN

struct BeforeHook : TagableHook
{
    explicit BeforeHook(const std::string& tag);
};

MANGO_NS_END

#endif
