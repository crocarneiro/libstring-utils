# include "../src/string-utils.h"
# include "unity/unity.h"

void shouldReturnASingleCharacter()
{
    char base_string[] = "Hello World";
    char new_string[2];

    substr(new_string, base_string, 5, 6);

    TEST_ASSERT_EQUAL_STRING(" ", new_string);
}

void shouldReturnAString()
{
    char base_string[] = "Hello World";
    char new_string[6];

    substr(new_string, base_string, 0, 5);

    TEST_ASSERT_EQUAL_STRING("Hello", new_string);
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(shouldReturnASingleCharacter);
    RUN_TEST(shouldReturnAString);
    return UNITY_END();
}