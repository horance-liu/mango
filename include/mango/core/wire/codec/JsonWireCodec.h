#ifndef HF75BE806_6F05_4FBD_9BDB_FD71CE0AD312
#define HF75BE806_6F05_4FBD_9BDB_FD71CE0AD312

#include "mango/core/wire/codec/WireCodec.h"

MANGO_NS_BEGIN

struct JsonWireCodec : WireCodec
{
    OVERRIDE(WireRequest* decode(const std::string& request) const);
    OVERRIDE(std::string encode(WireResponse& response) const);
};

MANGO_NS_END

#endif
