#ifndef H782A96EB_78F6_4268_A610_35D5D84C81FD
#define H782A96EB_78F6_4268_A610_35D5D84C81FD

#include "mango/core/model/Tags.h"

MANGO_NS_BEGIN

struct Scenario
{
    explicit Scenario(const Tags&);

    const Tags& getTags() const;

private:
    Tags tags;
};

MANGO_NS_END

#endif
