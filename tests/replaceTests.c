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

void shouldReplaceAStringWithSpecialCharecter()
{
    char baseString[] = "(% 1";
    char oldChar[] = "% 1";
    char newChar[] = " %1";

    TEST_ASSERT_EQUAL_STRING("( %1", replace(baseString, oldChar, newChar));
}

void shouldReplaceAStringWithSpecialCharecter2()
{
    char baseString[] = "( %1";
    char oldChar[] = "( %";
    char newChar[] = "(%";

    TEST_ASSERT_EQUAL_STRING("(%1", replace(baseString, oldChar, newChar));
}

void shouldReplaceAStringWithSpecialCharecter3()
{
    char baseString[] = "Sintonizando títulos (%1/% 2).";
    char oldChar[] = "% 2";
    char newChar[] = "%2";

    TEST_ASSERT_EQUAL_STRING("Sintonizando títulos (%1/%2).", replace(baseString, oldChar, newChar));
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(shouldReplaceASimpleString);
    RUN_TEST(shouldReplaceAWhitespace);
    RUN_TEST(shouldReplaceAStringWithSpecialCharecter);
    RUN_TEST(shouldReplaceAStringWithSpecialCharecter2);
    RUN_TEST(shouldReplaceAStringWithSpecialCharecter3);
    return UNITY_END();
}