# include "./unity/unity.h"
# include "../src/string-utils.h"

void shouldCorrectlyRpadSingleCharacter()
{
    TEST_ASSERT_EQUAL_STRING("test******", rpad("test", "*", 10));
}

void shouldReturnTheExactlySameString()
{
    TEST_ASSERT_EQUAL_STRING("1234567891011", rpad("1234567891011", "*", 10));
}

void shouldCorrectlyRpadString()
{
    TEST_ASSERT_EQUAL_STRING("helloworld", rpad("hello", "world", 10));
}

void shouldTruncThePadString()
{
    TEST_ASSERT_EQUAL_STRING("hello worl", rpad("hello ", "world", 10));
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