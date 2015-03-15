#ifndef H14873F96_2122_4471_8220_9DA5D2325C36
#define H14873F96_2122_4471_8220_9DA5D2325C36

#include <mango/core/step/concept/MatchingSteps.h>
#include <mango/core/step/concept/StepId.h>
#include <mango/core/step/concept/StepInvoker.h>
#include <mango/core/regex/Regex.h>
#include <string>

MANGO_NS_BEGIN

struct Step : StepInvoker
{
    Step(const StepId& id, const std::string& matcher, const std::string& source);

    const StepId& getId() const;
    void matches(const std::string& desc, MatchingSteps& matches) const;

private:
    StepId id;
    Regex regex;
    std::string source;
};

MANGO_NS_END

#endif
