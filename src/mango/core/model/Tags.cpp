#include "mango/core/model/Tags.h"
#include "l0-infra/std/algorithm.h"

MANGO_NS_BEGIN

void Tags::addTag(const std::string& tag)
{
    tags.push_back(tag);
}

inline bool Tags::contains(const std::string& tag) const
{
    return stdext::find(tags, tag) != tags.end();
}

bool Tags::contains(const Tags& rhs) const
{
    auto pred = [&](auto& tag) {
        return rhs.contains(tag);
    };

    return stdext::find_if(tags, pred) != tags.end();
}

MANGO_NS_END
