# include "../src/string-utils.h"
# include "unity/unity.h"

void shouldReplaceASimpleString()
{
    char base_string[] = "Hello Mundo";
    char new_string[12];
    char old_char[] = "Mundo";
    char new_char[] = "World";

    replace(new_string, base_string, old_char, new_char);

    TEST_ASSERT_EQUAL_STRING("Hello World", new_string);
}

void shouldReplaceAWhitespace()
{
    char base_string[] = "Hello World";
    char new_string[12];
    char old_char[] = " ";
    char new_char[] = ";";

    replace(new_string, base_string, old_char, new_char);

    TEST_ASSERT_EQUAL_STRING("Hello;World", new_string);
}

void shouldReplaceAStringWithSpecialCharecter()
{
    char base_string[] = "(% 1";
    char new_string[5];
    char old_char[] = "% 1";
    char new_char[] = " %1";

    replace(new_string, base_string, old_char, new_char);

    TEST_ASSERT_EQUAL_STRING("( %1", new_string);
}

void shouldReplaceAStringWithSpecialCharecter2()
{
    char base_string[] = "( %1";
    char new_string[4];
    char old_char[] = "( %";
    char new_char[] = "(%";

    replace(new_string, base_string, old_char, new_char);

    TEST_ASSERT_EQUAL_STRING("(%1", new_string);
}

void shouldReplaceAStringWithSpecialCharecter3()
{
    char base_string[] = "Sintonizando títulos (%1/% 2).";
    char new_string[31];
    char old_char[] = "% 2";
    char new_char[] = "%2";

    replace(new_string, base_string, old_char, new_char);

    TEST_ASSERT_EQUAL_STRING("Sintonizando títulos (%1/%2).", new_string);
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