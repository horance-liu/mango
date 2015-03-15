#include <mango/core/regex/RegexSubMatch.h>

MANGO_NS_BEGIN

RegexSubMatch::RegexSubMatch(const std::string& value, int position)
  : value(value)
  , position(position)
{
}

const std::string& RegexSubMatch::getValue() const
{
    return value;
}

int RegexSubMatch::getPosition() const
{
    return position;
}

MANGO_NS_END
