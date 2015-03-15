#ifndef H2E242EE0_34C3_4B3A_8412_C0520B3B116F
#define H2E242EE0_34C3_4B3A_8412_C0520B3B116F

#include <gtest/gtest.h>
#include "mango/core/model/Tags.h"
#include <initializer_list>

USING_MANGO_NS

struct TagExprFixture : testing::Test
{
    Tags toTags(std::initializer_list<const char*> tags)
    {
        Tags result;

        for (auto tag : tags)
        {
            result.addTag(tag);
        }

        return result;
    }
};

#define list_of(...) toTags({__VA_ARGS__})

#endif
