#ifndef H5F5AABAB_23DE_45BE_8B22_2E191A61A359
#define H5F5AABAB_23DE_45BE_8B22_2E191A61A359

#include <mango/core/model/InvokeArgs.h>
#include "mango/core/wire/request/WireRequest.h"

MANGO_NS_BEGIN

struct InvokeRequest : WireRequest
{
    InvokeRequest(const std::string& id, InvokeArgs& args);

private:
    OVERRIDE(WireResponse* run(Runner&) const);

private:
    std::string id;
    InvokeArgs args;
};

MANGO_NS_END

#endif
