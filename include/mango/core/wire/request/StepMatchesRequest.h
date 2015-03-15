#ifndef H32B4B90D_1C7E_481A_A15E_42A4C9A62358
#define H32B4B90D_1C7E_481A_A15E_42A4C9A62358

#include "mango/core/wire/request/WireRequest.h"
#include <string>

MANGO_NS_BEGIN

struct StepMatchesRequest : WireRequest
{
    explicit StepMatchesRequest(const std::string& stepName);

private:
    OVERRIDE(WireResponse* run(Runner&) const);

private:
    std::string stepName;
};

MANGO_NS_END

#endif
