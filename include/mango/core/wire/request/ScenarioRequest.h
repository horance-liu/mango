#ifndef HBB32C8D8_34D2_43C7_B328_196B4693D233
#define HBB32C8D8_34D2_43C7_B328_196B4693D233

#include "mango/core/wire/request/WireRequest.h"
#include "mango/core/model/Tags.h"

MANGO_NS_BEGIN

struct ScenarioRequest : WireRequest
{
    ScenarioRequest(const Tags& tags);

protected:
    Tags tags;
};

MANGO_NS_END

#endif
