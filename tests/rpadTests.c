# include "./unity/unity.h"
# include "../src/string-utils.h"

void shouldCorrectlyRpadSingleCharacter()
{
    char new_string[11];
    rpad(new_string, "test", "*", 10);

    TEST_ASSERT_EQUAL_STRING("test******", new_string);
}

void shouldReturnTheExactlySameString()
{
    char new_string[11];
    rpad(new_string, "1234567891011", "*", 10);

    TEST_ASSERT_EQUAL_STRING("1234567891011", new_string);
}

void shouldCorrectlyRpadString()
{
    char new_string[11];
    rpad(new_string, "hello", "world", 10);

    TEST_ASSERT_EQUAL_STRING("helloworld", new_string);
}

void shouldTruncThePadString()
{
    char new_string[11];
    rpad(new_string, "hello ", "world", 10);

    TEST_ASSERT_EQUAL_STRING("hello worl", new_string);
}

int main()
{
    UNITY_BEGIN();

    RUN_TEST(shouldCorrectlyRpadSingleCharacter);
    RUN_TEST(shouldReturnTheExactlySameString);
    RUN_TEST(shouldCorrectlyRpadString);
    RUN_TEST(shouldTruncThePadString);

    return UNITY_END();
}