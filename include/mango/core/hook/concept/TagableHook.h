#ifndef H7BFF354D_D699_4873_91BE_FF8B10EEDD12
#define H7BFF354D_D699_4873_91BE_FF8B10EEDD12

#include "mango/infra/dci/Role.h"
#include "mango/core/base/mango.h"
#include <string>

MANGO_NS_BEGIN

struct TagExpr;
struct Scenario;

DEFINE_ROLE(TagableHook)
{
    explicit TagableHook(const std::string& tag);
    ~TagableHook();

    void invokeHook(const Scenario& scenario);

private:
    DEFAULT(void, skipHook());
    ABSTRACT(void invoke());

protected:
    bool tagsMatch(const Scenario& scenario) const;

private:
    TagExpr* tagExpr;
};

MANGO_NS_END

#endif
