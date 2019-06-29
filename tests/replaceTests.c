# include "../src/string-utils.h"
# include "unity/unity.h"

void shouldReplaceASimpleString()
{
    char baseString[] = "Hello Mundo";
    char oldChar[] = "Mundo";
    char newChar[] = "World";

    TEST_ASSERT_EQUAL_STRING("Hello World", replace(baseString, oldChar, newChar));
}

void shouldReplaceAWhitespace()
{
    char baseString[] = "Hello World";
    char oldChar[] = " ";
    char newChar[] = ";";

    TEST_ASSERT_EQUAL_STRING("Hello;World", replace(baseString, oldChar, newChar));
}

void shouldReplaceAStringWhithSpecialCharecter()
{
    char baseString[] = "(% 1";
    char oldChar[] = "% 1";
    char newChar[] = " %1";

    TEST_ASSERT_EQUAL_STRING("( %1", replace(baseString, oldChar, newChar));
}

void shouldReplaceAStringWhithSpecialCharecter2()
{
    char baseString[] = "( %1";
    char oldChar[] = "( %";
    char newChar[] = "(%";

    TEST_ASSERT_EQUAL_STRING("(%1", replace(baseString, oldChar, newChar));
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(shouldReplaceASimpleString);
    RUN_TEST(shouldReplaceAWhitespace);
    RUN_TEST(shouldReplaceAStringWhithSpecialCharecter);
    return UNITY_END();
}