#ifndef HCE9D5986_E1B8_4CAD_A534_7F137FA55856
#define HCE9D5986_E1B8_4CAD_A534_7F137FA55856

#include <mango/core/step/concept/MatchingSteps.h>
#include "mango/core/wire/response/WireResponse.h"

MANGO_NS_BEGIN

struct StepMatchesResponse : WireResponse
{
    StepMatchesResponse(MatchingSteps& matchingSteps);

    const MatchingSteps& getMatchingSteps() const;

private:
    OVERRIDE(void accept(WireResponseVisitor&) const);

private:
    MatchingSteps matchingSteps;
};

MANGO_NS_END

#endif
