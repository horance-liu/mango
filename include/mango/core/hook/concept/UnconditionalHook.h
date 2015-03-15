#ifndef HAFED7D24_A66B_46AD_86AA_EE8A77C6F592
#define HAFED7D24_A66B_46AD_86AA_EE8A77C6F592

#include "infra/dci/Role.h"
#include "mango/base/mango.h"

MANGO_NS_BEGIN

DEFINE_ROLE(UnconditionalHook)
{
    ABSTRACT(void invoke());
};

MANGO_NS_END

#endif
