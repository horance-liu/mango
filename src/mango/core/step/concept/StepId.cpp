#include <mango/core/step/concept/StepId.h>
#include <infra/std/string.h>

MANGO_NS_BEGIN

StepId::StepId(unsigned id)
    : id(id)
{}

StepId::StepId(const std::string& id)
  : id(stdext::string_as<unsigned int>(id))
{
}

std::string StepId::toString() const
{
    return stdext::to_string(id);
}

bool StepId::operator<(const StepId& rhs) const
{
    return id < rhs.id;
}

MANGO_NS_END
