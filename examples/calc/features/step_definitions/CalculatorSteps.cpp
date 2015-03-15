#include <mango/mango.hpp>
#include <Calculator.h>

STEPS(Calculator)
{
    Calculator calculator;
    int result;

    GIVEN("^I have entered (\\d+) into the calculator$")
    {
        PARAM_0(int, n);

        calculator.push(n);
    }

    WHEN("^I press add$")
    {
        result = calculator.add();
    }

    THEN("^the result should be (.*) on the screen$")
    {
        PARAM_0(int, expected);

        ASSERT_EQ(expected, result);
    }
};
