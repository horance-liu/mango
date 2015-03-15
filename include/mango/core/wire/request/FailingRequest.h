#ifndef H343BC622_F786_4135_B875_55693CA8294A
#define H343BC622_F786_4135_B875_55693CA8294A

#include "mango/core/wire/request/WireRequest.h"

MANGO_NS_BEGIN

struct FailingRequest : WireRequest
{
    OVERRIDE(WireResponse* run(Runner&) const);
};

MANGO_NS_END

#endif
