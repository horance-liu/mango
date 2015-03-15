#ifndef H87102185_8997_425E_AFCB_749FCEC7A7AF
#define H87102185_8997_425E_AFCB_749FCEC7A7AF

#include <mango/core/step/concept/StepsFactory.h>
#include <mango/core/step/registry/StepRegistry.h>
#include "mango/core/step/concept/Step.h"
#include "mango/core/runtime/Runtime.h"
#include <map>

MANGO_NS_BEGIN

struct StepRegistry;

template <unsigned Id, typename StepDefinition>
struct GenericStep : Step
{
private:
    using step_definition_type = void (StepDefinition::*)(const InvokeArgs&);

public:
    GenericStep
        ( const std::string& matcher
        , const std::string& source
        , step_definition_type definition)
        : Step(Id, matcher, source)
        , definition(definition)
    {
        REGISTRY(StepRegistry, registry);
        registry.addStep(*this);
    }

private:
    OVERRIDE(void invokeStep(const InvokeArgs& args) const)
    {
        (StepsFactory::create<StepDefinition>().*definition)(args);
    }

private:
    step_definition_type definition;
};

MANGO_NS_END

#endif
