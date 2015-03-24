#ifndef H7C246A07_7084_4AF6_AAEB_E255ADE0C740
#define H7C246A07_7084_4AF6_AAEB_E255ADE0C740

#include "l0-infra/base/Role.h"
#include "mango/core/base/mango.h"

MANGO_NS_BEGIN

struct SuccessResponse;
struct FailureResponse;
struct PendingResponse;
struct StepMatchesResponse;
struct SnippetTextResponse;

DEFINE_ROLE(WireResponseVisitor)
{
    ABSTRACT(void visitSuccessResponse(const SuccessResponse&));
    ABSTRACT(void visitFailureResponse(const FailureResponse&));
    ABSTRACT(void visitPendingResponse(const PendingResponse&));
    ABSTRACT(void visitStepMatchesResponse(const StepMatchesResponse&));
    ABSTRACT(void visitSnippetTextResponse(const SnippetTextResponse&));
};

MANGO_NS_END

#endif
