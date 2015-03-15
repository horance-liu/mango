#include "mango/core/tag/OrTagExpr.h"
#include "TagExprFixture.h"

struct OrTagExprTest : TagExprFixture {};

TEST_F(OrTagExprTest, empty_expr_should_not_matches_anything)
{
    OrTagExpr expr("");
    ASSERT_FALSE(expr.matches(list_of("x")));
    ASSERT_FALSE(expr.matches(list_of("a", "b")));
}

TEST_F(OrTagExprTest, single_expression_should_matches_the_specified_tag)
{
    OrTagExpr expr("@a");
    ASSERT_TRUE(expr.matches(list_of("a")));
    ASSERT_FALSE(expr.matches(list_of("x")));
}

TEST_F(OrTagExprTest, multi_expr_should_match_one_of_tags)
{
    OrTagExpr expr("@a,@b,@c");
    ASSERT_TRUE(expr.matches(list_of("b")));
    ASSERT_TRUE(expr.matches(list_of("a")));
    ASSERT_TRUE(expr.matches(list_of("b")));
    ASSERT_TRUE(expr.matches(list_of("a", "b")));
    ASSERT_TRUE(expr.matches(list_of("a", "b", "c")));
    ASSERT_TRUE(expr.matches(list_of("x", "a", "b")));
    ASSERT_TRUE(expr.matches(list_of("a", "y")));
    ASSERT_TRUE(expr.matches(list_of("x", "b")));
    ASSERT_FALSE(expr.matches(list_of("x", "y", "z")));
}

TEST_F(OrTagExprTest, should_allow_space)
{
    OrTagExpr expr("@a, \t    @b,   @c  ");
    ASSERT_TRUE(expr.matches(list_of("b")));
    ASSERT_FALSE(expr.matches(list_of("x")));
}
