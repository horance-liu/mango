#include <mango/core/runtime/Runner.h>
#include "mango/core/wire/request/BeginScenarioRequest.h"
#include "mango/core/wire/response/SuccessResponse.h"

MANGO_NS_BEGIN

WireResponse* BeginScenarioRequest::run(Runner& runner) const
{
    runner.beginScenario(tags);
    return new SuccessResponse;
}

MANGO_NS_END
