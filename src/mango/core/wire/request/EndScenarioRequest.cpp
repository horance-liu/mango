#include <mango/core/runtime/Runner.h>
#include "mango/core/wire/request/EndScenarioRequest.h"
#include "mango/core/wire/response/SuccessResponse.h"

MANGO_NS_BEGIN

WireResponse* EndScenarioRequest::run(Runner& runner) const
{
    runner.endScenario(tags);
    return new SuccessResponse;
}

MANGO_NS_END
