#include "mango/core/tag/AndTagExpr.h"
#include "TagExprFixture.h"

struct AndTagExprTest : TagExprFixture {};

TEST_F(AndTagExprTest, empty_expr_should_matches_any_tag)
{
    AndTagExpr expr("");
    ASSERT_TRUE(expr.matches(list_of("x")));
    ASSERT_TRUE(expr.matches(list_of("a", "b")));
}

TEST_F(AndTagExprTest, single_expression_should_matches_the_specified_tag)
{
    AndTagExpr expr("\"@a\"");
    ASSERT_TRUE(expr.matches(list_of("a")));
    ASSERT_FALSE(expr.matches(list_of("x")));
}

TEST_F(AndTagExprTest, multi_expr_should_match_every_specified_tag)
{
    AndTagExpr expr("\"@a\",\"@b\"");
    ASSERT_TRUE(expr.matches(list_of("a", "b")));
    ASSERT_TRUE(expr.matches(list_of("x", "a", "b")));
    ASSERT_FALSE(expr.matches(list_of("a")));
    ASSERT_FALSE(expr.matches(list_of("b")));
    ASSERT_FALSE(expr.matches(list_of("a", "y")));
    ASSERT_FALSE(expr.matches(list_of("x", "b")));
    ASSERT_FALSE(expr.matches(list_of("x", "y")));
}

TEST_F(AndTagExprTest, should_allow_spaces)
{
    AndTagExpr expr(" \"@a  \t \" ,  \t \"@b\" ");
    ASSERT_TRUE(expr.matches(list_of("a", "b")));
    ASSERT_FALSE(expr.matches(list_of("a")));
}

TEST_F(AndTagExprTest, should_handle_composite_tag_expressions)
{
    AndTagExpr expr("\"@a,@b\", \"@c\", \"@d,@e,@f\"");
    ASSERT_TRUE(expr.matches(list_of("a", "c", "d")));
    ASSERT_FALSE(expr.matches(list_of("x", "c", "f")));
}
