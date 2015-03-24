#include "Calculator.h"
#include "l0-infra/std/algorithm.h"
#include <limits>

void Calculator::push(int n)
{
    values.push_back(n);
}

int Calculator::add()
{
    return stdext::reduce(values, 0.0,
            [](auto& result, auto& v) { result += v; });
}
