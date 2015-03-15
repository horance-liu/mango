#ifndef H5F5BA50E_70B6_4C28_A319_7C43461D683E
#define H5F5BA50E_70B6_4C28_A319_7C43461D683E

#include "mango/core/base/mango.h"
#include "mango/infra/dci/Role.h"
#include <string>

MANGO_NS_BEGIN

struct WireRequest;
struct WireResponse;

DEFINE_ROLE(WireCodec)
{
    ABSTRACT(WireRequest* decode(const std::string& request) const);
    ABSTRACT(std::string encode(WireResponse& response) const);
};

MANGO_NS_END

#endif
