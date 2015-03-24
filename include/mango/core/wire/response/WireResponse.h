#ifndef H0C1CDC44_98C6_44C7_B449_3D4B85D406A1
#define H0C1CDC44_98C6_44C7_B449_3D4B85D406A1

#include "l0-infra/base/Role.h"
#include "mango/core/base/mango.h"

MANGO_NS_BEGIN

struct WireResponseVisitor;

DEFINE_ROLE(WireResponse)
{
    ABSTRACT(void accept(WireResponseVisitor&) const);
};

MANGO_NS_END

#endif
