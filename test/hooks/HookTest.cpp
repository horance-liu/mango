#include "mango/mango.hpp"
#include <mango/core/runtime/Runner.h>
#include <sstream>

USING_MANGO_NS

namespace
{
    std::stringstream before_all_stream;
    std::stringstream before_stream;
    std::stringstream after_stream;

    struct HookTest : testing::Test
    {
        void TearDown()
        {
            before_all_stream.str("");
            before_stream.str("");
            after_stream.str("");
        }

        Runner& runner = Runtime::runtime().ROLE(Runner);

    };
}

namespace
{
    BEFORE_ALL() { before_all_stream << "A"; }
    BEFORE_ALL() { before_all_stream << "B"; }
}

TEST_F(HookTest, should_run_all_of_BEFORE_ALL_hooks_at_begining)
{
    runner.beginScenario(Tags());

    ASSERT_EQ("AB", before_all_stream.str());

    runner.endScenario(Tags());
}

namespace
{
    BEFORE() { before_stream << "C"; }
    BEFORE() { before_stream << "D"; }
}

TEST_F(HookTest, should_run_all_of_BEFORE_hooks_before_exec_scenario)
{
    runner.beginScenario(Tags());

    ASSERT_EQ("CD", before_stream.str());

    runner.endScenario(Tags());
}


namespace
{
    AFTER() { after_stream << "E"; }
    AFTER() { after_stream << "F"; }
}

TEST_F(HookTest, should_run_all_of_AFTER_hooks_after_exec_scenario)
{
    runner.beginScenario(Tags());
    runner.endScenario(Tags());

    ASSERT_EQ("EF", after_stream.str());
}
