#include "mango/core/model/Tags.h"
#include "mango/infra/std/algorithm.h"

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
    auto pred = [&](const std::string& tag) {
        return rhs.contains(tag);
    };

    return stdext::find_if(tags, pred) != tags.end();
}

MANGO_NS_END
