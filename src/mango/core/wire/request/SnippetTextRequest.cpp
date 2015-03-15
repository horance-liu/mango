#include <mango/core/runtime/Runner.h>
#include "mango/core/wire/request/SnippetTextRequest.h"
#include "mango/core/wire/response/SnippetTextResponse.h"

MANGO_NS_BEGIN

SnippetTextRequest::SnippetTextRequest
    ( const std::string& keyword
    , const std::string& name
    , const std::string& multilineArg)
    : keyword(keyword)
    , name(name)
    , multilineArg(multilineArg)
{
}

WireResponse* SnippetTextRequest::run(Runner& runner) const
{
    return new SnippetTextResponse
            (runner.snippetText(keyword, name, multilineArg));
}

MANGO_NS_END
