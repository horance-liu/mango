#ifndef H1702BD08_889B_4FB7_A63A_BEF6F26551C3
#define H1702BD08_889B_4FB7_A63A_BEF6F26551C3

#include "mango/core/wire/request/ScenarioRequest.h"

MANGO_NS_BEGIN

struct BeginScenarioRequest : ScenarioRequest
{
    using ScenarioRequest::ScenarioRequest;

private:
    OVERRIDE(WireResponse* run(Runner&) const);
};

MANGO_NS_END

#endif
