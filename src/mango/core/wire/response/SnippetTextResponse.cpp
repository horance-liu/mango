#include "mango/core/wire/response/SnippetTextResponse.h"
#include "mango/core/wire/response/WireResponseVisitor.h"

MANGO_NS_BEGIN

SnippetTextResponse::SnippetTextResponse(const std::string& stepSnippet)
  : stepSnippet(stepSnippet)
{
}

void SnippetTextResponse::accept(WireResponseVisitor& visitor) const
{
    visitor.visitSnippetTextResponse(*this);
}

const std::string& SnippetTextResponse::getStepSnippet() const
{
    return stepSnippet;
}

MANGO_NS_END
