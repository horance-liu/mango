#ifndef H3D7EA396_E47B_41B8_8B5B_E7239D16FC4C
#define H3D7EA396_E47B_41B8_8B5B_E7239D16FC4C

#include "mango/core/base/mango.h"
#include <string>

MANGO_NS_BEGIN

struct RegexSubMatch
{
    RegexSubMatch(const std::string& value, int position = -1);

    const std::string& getValue() const;
    int getPosition() const;

private:
    std::string value;
    int position;
};

MANGO_NS_END

#endif
