#ifndef HD436CA6B_204F_4128_ADA9_376B0C07DE64
#define HD436CA6B_204F_4128_ADA9_376B0C07DE64

#include "mango/base/mango.h"
#include <string>

MANGO_NS_BEGIN

struct StepId
{
    StepId(unsigned id);
    StepId(const std::string& id);

    std::string toString() const;

    bool operator<(const StepId&) const;

private:
    unsigned id;
};

MANGO_NS_END

#endif
