#ifndef H10A69FED_5D4A_4F1B_82E0_B543DD5F44FF
#define H10A69FED_5D4A_4F1B_82E0_B543DD5F44FF

#include "mango/core/wire/request/ScenarioRequest.h"

MANGO_NS_BEGIN

struct EndScenarioRequest : ScenarioRequest
{
    using ScenarioRequest::ScenarioRequest;

private:
    OVERRIDE(WireResponse* run(Runner&) const);
};

MANGO_NS_END

#endif
