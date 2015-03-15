#ifndef H7F6EE8AE_D5D0_480C_AB90_F070DB50D657
#define H7F6EE8AE_D5D0_480C_AB90_F070DB50D657

#include "mango/core/wire/response/WireResponse.h"
#include <string>

MANGO_NS_BEGIN

struct PendingResponse : WireResponse
{
    explicit PendingResponse(const std::string&);

    const std::string& getMsg() const;

private:
    OVERRIDE(void accept(WireResponseVisitor&) const);

private:
    std::string msg;
};

MANGO_NS_END

#endif
