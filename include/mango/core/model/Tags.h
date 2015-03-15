#ifndef H0682A422_B8B4_4C34_A529_515976E73C68
#define H0682A422_B8B4_4C34_A529_515976E73C68

#include "mango/core/base/mango.h"
#include <vector>
#include <string>

MANGO_NS_BEGIN

struct Tags
{
    void addTag(const std::string& tag);
    bool contains(const Tags& rhs) const;

private:
    bool contains(const std::string& tag) const;

private:
    std::vector<std::string> tags;
};

MANGO_NS_END

#endif
