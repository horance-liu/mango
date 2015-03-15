#include <mango/core/except/PendingStepException.h>

MANGO_NS_BEGIN

PendingStepException::PendingStepException(const std::string& msg)
  : msg(msg)
{}

const std::string& PendingStepException::getMsg() const
{
    return msg;
}

MANGO_NS_END
