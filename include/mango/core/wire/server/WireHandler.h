#ifndef H04803ABB_80FE_4F8A_8492_1AD95E3AD747
#define H04803ABB_80FE_4F8A_8492_1AD95E3AD747

#include "mango/core/base/mango.h"
#include "mango/infra/dci/Role.h"
#include <string>

MANGO_NS_BEGIN

struct WireCodec;
struct Runner;

DEFINE_ROLE(WireHandler)
{
    std::string handle(const std::string& cmd) const;

private:
    USE_ROLE(WireCodec);
    USE_ROLE(Runner);
};

MANGO_NS_END

#endif
