#include "mango/core/model/Scenario.h"

MANGO_NS_BEGIN

Scenario::Scenario(const Tags& tags)
  : tags(tags)
{
}

const Tags& Scenario::getTags() const
{
    return tags;
}

MANGO_NS_END
