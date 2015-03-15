#include <gtest/gtest.h>
#include <mango/infra/std/algorithm.h>
#include <mango/infra/std/static_assert.h>

namespace
{
    int arr[] = {-1, -2, 3, 4};
    std::vector<int> v1 {-1, -2, 3, 4};
    const std::vector<int> v2 {-1, -2, 3, 4};
}

TEST(higher_order_functions, find_support_non_const_container)
{
    auto found = stdext::find(v1, 3);

    STATIC_ASSERT_TYPE(std::vector<int>::iterator, found);
    ASSERT_EQ(3, *found);
}

TEST(higher_order_functions, find_support_const_container)
{
    auto found = stdext::find(v2, 3);

    STATIC_ASSERT_TYPE(std::vector<int>::const_iterator, found);
    ASSERT_EQ(3, *found);
}

TEST(higher_order_functions, find_if_support_non_const_container)
{
    auto found = stdext::find_if(v1, [](auto e) { return e > 0; });

    STATIC_ASSERT_TYPE(std::vector<int>::iterator, found);
    ASSERT_EQ(3, *found);
}

TEST(higher_order_functions, find_if_support_const_container)
{
    auto found = stdext::find_if(v2, [](auto e) { return e > 0; });

    STATIC_ASSERT_TYPE(std::vector<int>::const_iterator, found);
    ASSERT_EQ(3, *found);
}

TEST(higher_order_functions, map)
{
    std::vector<int> v;
    stdext::map(v1, std::back_inserter(v), [](auto e) { return e > 0 ? e : -e; });

    ASSERT_EQ(1, v[0]);
    ASSERT_EQ(2, v[1]);
    ASSERT_EQ(3, v[2]);
    ASSERT_EQ(4, v[3]);
}

TEST(higher_order_functions, reduce_int)
{
    auto sum = stdext::reduce(arr, 0, [](auto& sum, auto e) { sum += e; });

    ASSERT_EQ(4, sum);
}

TEST(higher_order_functions, reduce_string)
{
    auto upper = stdext::reduce(std::string("cpp"), std::string(),
            [](auto &result, auto c) { result += toupper(c); });

    ASSERT_EQ("CPP", upper);
}

TEST(higher_order_functions, filter)
{
    std::vector<int> v;
    stdext::filter(arr, std::back_inserter(v), [](auto e) { return e > 0; });

    ASSERT_EQ(3, v[0]);
    ASSERT_EQ(4, v[1]);
}

TEST(higher_order_functions, each)
{
    auto sum = 0;
    stdext::each(arr, [&sum](auto e) { sum += e; });

    ASSERT_EQ(4, sum);
}
