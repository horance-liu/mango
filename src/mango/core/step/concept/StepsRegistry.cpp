#include <mango/core/step/concept/StepsRegistry.h>
#include "l0-infra/std/algorithm.h"

MANGO_NS_BEGIN

StepsRegistry::~StepsRegistry()
{
    stdext::clear(registry);
}

MANGO_NS_END
