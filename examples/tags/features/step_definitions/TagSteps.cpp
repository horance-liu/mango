#include <mango/mango.hpp>
#include <iostream>

BEFORE_ALL()
{
    std::cout << "-------------------- (Before all scenarios)" << std::endl;
}

AFTER_ALL()
{
    std::cout << "-------------------- (After all scenarios)" << std::endl;
}

BEFORE()
{
    std::cout << "-------------------- (Before any scenario)" << std::endl;
}

AFTER()
{
    std::cout << "-------------------- (After any scenario)" << std::endl;
}

BEFORE("@foo,@bar","@baz")
{
    std::cout << "Before scenario (\"@foo,@baz\",\"@bar\")" << std::endl;
}

AROUND_STEP("@baz")
{
    std::cout << "Around step (\"@baz\") ...before" << std::endl;
    step->call();
    std::cout << "Around step (\"@baz\") ..after" << std::endl;
}

AFTER_STEP("@bar")
{
    std::cout << "After step (\"@bar\")" << std::endl;
}

AFTER("@foo")
{
    std::cout << "After scenario (\"@foo\")" << std::endl;
}

AFTER("@gherkin")
{
    std::cout << "After scenario (\"@gherkin\")" << std::endl;
}

AROUND_STEP()
{
    std::cout << "Around step 1 ...before" << std::endl;
    step->call();
    std::cout << "Around step 1 ...after" << std::endl;
}

AROUND_STEP()
{
    std::cout << "Around step 2 ...before" << std::endl;
    step->call();
    std::cout << "Around step 2 ...after" << std::endl;
}

STEPS(Tags)
{
    GIVEN("^I'm running a step from a scenario not tagged$")
    {
        std::cout << "Running step from scenario without tags" << std::endl;
    }

    THEN("^I'm running a step from a scenario tagged with (.*)$") {
        PARAM_0(std::string, tags);

        std::cout << "Running step from scenario with tags: " << tags << std::endl;

        ASSERT_TRUE(true);
    }
};

