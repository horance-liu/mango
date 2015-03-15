#ifndef H91FD5F93_A5EC_4007_AC67_6BA921F539E0
#define H91FD5F93_A5EC_4007_AC67_6BA921F539E0

#include "infra/dci/Role.h"
#include "mango/base/mango.h"

MANGO_NS_BEGIN

struct Runner;
struct WireResponse;

DEFINE_ROLE(WireRequest)
{
    ABSTRACT(WireResponse* run(Runner&) const);
};

MANGO_NS_END

#endif
