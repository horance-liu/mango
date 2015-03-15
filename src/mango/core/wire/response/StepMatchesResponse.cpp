#include "mango/core/wire/response/StepMatchesResponse.h"
#include "mango/core/wire/response/WireResponseVisitor.h"

MANGO_NS_BEGIN

StepMatchesResponse::StepMatchesResponse(MatchingSteps& matchingSteps)
  : matchingSteps(std::move(matchingSteps))
{
}

void StepMatchesResponse::accept(WireResponseVisitor& visitor) const
{
    visitor.visitStepMatchesResponse(*this);
}

const MatchingSteps& StepMatchesResponse::getMatchingSteps() const
{
    return matchingSteps;
}

MANGO_NS_END
