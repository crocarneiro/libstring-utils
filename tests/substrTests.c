# include "../src/string-utils.h"
# include "unity/unity.h"

void shouldReturnASingleCharacter()
{
    char baseString[] = "Hello World";
    TEST_ASSERT_EQUAL_STRING(" ", substr(baseString, 5, 6));
}

void shouldReturnAString()
{
    char baseString[] = "Hello World";
    TEST_ASSERT_EQUAL_STRING("Hello", substr(baseString, 0, 5));
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(shouldReturnASingleCharacter);
    RUN_TEST(shouldReturnAString);
    return UNITY_END();
}