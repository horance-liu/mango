#ifndef H9714A243_DE2D_4609_A80A_42FF8435F1A5
#define H9714A243_DE2D_4609_A80A_42FF8435F1A5

#include "mango/core/base/mango.h"
#include <string>

MANGO_NS_BEGIN

struct PendingStepException
{
    explicit PendingStepException(const std::string& msg);

    const std::string& getMsg() const;

private:
    const std::string msg;
};

MANGO_NS_END

#endif
