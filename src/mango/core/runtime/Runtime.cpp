#include <mango/core/runtime/Runner.h>
#include <mango/core/step/registry/StepRegistry.h>
#include "mango/core/runtime/Runtime.h"
#include "mango/core/wire/server/WireHandler.h"
#include "mango/core/wire/server/WireServer.h"
#include "mango/core/wire/codec/JsonWireCodec.h"
#include "l0-infra/std/string.h"
#include "gtest/gtest.h"

MANGO_NS_BEGIN

namespace
{
    struct RuntimeImpl
         : Runtime
         , private WireHandler
         , private WireServer
         , private JsonWireCodec
         , private Runner
         , private StepRegistry
    {
        ~RuntimeImpl()
        {
            if(SELF(*this, Runner).hasStarted())
            {
                ROLE(AfterAllHookRegistry).execHooks();
            }
        }


    private:
        OVERRIDE(int run(int argc, char **argv))
        {
            initGoogleTest(argc, argv);
            startServer(SELF(*this, WireServer), getPort(argc, argv));
            return 0;
        }

    private:
        static void initGoogleTest(int argc, char **argv)
        {
            ::testing::GTEST_FLAG(throw_on_failure) = true;
            ::testing::GTEST_FLAG(break_on_failure) = false;
            ::testing::GTEST_FLAG(catch_exceptions) = true;

            ::testing::InitGoogleTest(&argc, argv);
        }

        static void startServer(WireServer& server, unsigned int port)
        {
            server.listen(port);
            server.accept();
        }

        static unsigned short getPort(int argc, char **argv)
        {
            return argc > 1 ? stdext::string_as<int>(argv[1]) : 3902;
        }

    private:
        IMPL_ROLE(WireHandler);
        IMPL_ROLE(WireCodec);
        IMPL_ROLE(Runner);
        IMPL_ROLE(StepRegistry);

        IMPL_ROLE_WITH_ROLE_VAR(BeforeHookRegistry);
        IMPL_ROLE_WITH_ROLE_VAR(AfterHookRegistry);
        IMPL_ROLE_WITH_ROLE_VAR(AfterStepHookRegistry);
        IMPL_ROLE_WITH_ROLE_VAR(AroundStepHookRegistry);
        IMPL_ROLE_WITH_ROLE_VAR(BeforeAllHookRegistry);
        IMPL_ROLE_WITH_ROLE_VAR(AfterAllHookRegistry);
    };
}

Runtime& Runtime::runtime()
{
    static RuntimeImpl runtime;
    return runtime;
}

MANGO_NS_END
