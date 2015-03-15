#ifndef H22CD4A71_F5C5_426F_B4D7_4F673D1A6447
#define H22CD4A71_F5C5_426F_B4D7_4F673D1A6447

#include "mango/core/wire/request/WireRequest.h"
#include <string>

MANGO_NS_BEGIN

struct SnippetTextRequest : WireRequest
{
    SnippetTextRequest
        ( const std::string& keyword
        , const std::string& name
        , const std::string& multilineArg);

private:
    OVERRIDE(WireResponse* run(Runner&) const);

private:
    std::string keyword, name, multilineArg;
};

MANGO_NS_END

#endif
