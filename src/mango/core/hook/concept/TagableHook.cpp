#include "mango/core/hook/concept/TagableHook.h"
#include "mango/core/tag/AndTagExpr.h"
#include "mango/core/model/Scenario.h"

MANGO_NS_BEGIN

TagableHook::TagableHook(const std::string& tag)
  : tagExpr(new AndTagExpr(tag))
{}

TagableHook::~TagableHook()
{
    delete tagExpr;
}

bool TagableHook::tagsMatch(const Scenario& scenario) const {
    return tagExpr->matches(scenario.getTags());
}

void TagableHook::invokeHook(const Scenario& scenario)
{
    tagsMatch(scenario) ?  invoke() : skipHook();
}

MANGO_NS_END
