#include <mango/core/runtime/Runner.h>
#include "mango/core/wire/request/StepMatchesRequest.h"
#include "mango/core/wire/response/StepMatchesResponse.h"

MANGO_NS_BEGIN

StepMatchesRequest::StepMatchesRequest(const std::string& stepName)
  : stepName(stepName)
{
}

WireResponse* StepMatchesRequest::run(Runner& runner) const
{
    MatchingSteps matches;
    return new StepMatchesResponse(runner.stepMatches(stepName, matches));
}

MANGO_NS_END
