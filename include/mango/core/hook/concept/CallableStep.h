#ifndef HEA888604_0737_4DB7_A0B5_3F9008832B15
#define HEA888604_0737_4DB7_A0B5_3F9008832B15

#include "mango/base/mango.h"
#include "infra/dci/Role.h"

MANGO_NS_BEGIN

DEFINE_ROLE(CallableStep)
{
    ABSTRACT(void call());
};

MANGO_NS_END

#endif
