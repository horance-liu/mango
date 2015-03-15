#include "infra/std/string.h"
#include "infra/std/algorithm.h"

STDEXT_NS_BEGIN

std::string to_upper(const std::string& str)
{
    return stdext::reduce(str, std::string(),
            [](auto &result, auto c) { return result += toupper(c); });
}

std::string to_lower(const std::string& str)
{
    return stdext::reduce(str, std::string(),
            [](auto &result, auto c) { return result += tolower(c); });
}

STDEXT_NS_END
