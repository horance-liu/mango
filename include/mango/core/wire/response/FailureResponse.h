#ifndef H612E0B93_F6E0_48EB_A489_34D911D77A9F
#define H612E0B93_F6E0_48EB_A489_34D911D77A9F

#include "mango/core/wire/response/WireResponse.h"
#include <string>

MANGO_NS_BEGIN

struct FailureResponse : WireResponse
{
    FailureResponse(const std::string& msg = "");

    const std::string& getMsg() const;

private:
    OVERRIDE(void accept(WireResponseVisitor&) const);

private:
    std::string msg;
};

MANGO_NS_END

#endif
