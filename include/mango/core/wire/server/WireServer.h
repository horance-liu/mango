#ifndef HF5E3F9E8_A264_4EC6_9C3B_D8AF640E09BD
#define HF5E3F9E8_A264_4EC6_9C3B_D8AF640E09BD

#include "mango/core/base/mango.h"
#include "l0-infra/base/Role.h"

MANGO_NS_BEGIN

struct WireHandler;
struct WireServerImpl;

DEFINE_ROLE(WireServer)
{
    WireServer();
    ~WireServer();

    void listen(unsigned short port);
    void accept();

private:
    WireServerImpl* impl;

private:
    USE_ROLE(WireHandler);
};

MANGO_NS_END

#endif
