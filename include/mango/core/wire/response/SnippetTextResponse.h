#ifndef H09E22179_FBFE_4ED0_B0DF_B481A78F4055
#define H09E22179_FBFE_4ED0_B0DF_B481A78F4055

#include "mango/core/wire/response/WireResponse.h"
#include <string>

MANGO_NS_BEGIN

struct SnippetTextResponse : WireResponse
{
    explicit SnippetTextResponse(const std::string& stepSnippet);

    const std::string& getStepSnippet() const;

private:
    OVERRIDE(void accept(WireResponseVisitor& visitor) const);

private:
    const std::string stepSnippet;
};

MANGO_NS_END

#endif
