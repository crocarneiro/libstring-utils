# include "../src/string-utils.h"
# include "unity/unity.h"

void shouldReturnZeroSearchingAWhitespace()
{
    char base_string[] = "Hello World";
    char keyword[] = " ";
    int ini, end;

    int result = idxof(base_string, keyword, &ini, &end);

    TEST_ASSERT_EQUAL_INT(FOUND, result);
    TEST_ASSERT_EQUAL_INT(5, ini);
    TEST_ASSERT_EQUAL_INT(6, end);
}

void shouldReturnZeroSearchingAString()
{
    char base_string[] = "Hello World";
    char keyword[] = "Hello";
    int ini, end;

    int result = idxof(base_string, keyword, &ini, &end);

    TEST_ASSERT_EQUAL_INT(FOUND, result);
    TEST_ASSERT_EQUAL_INT(0, ini);
    TEST_ASSERT_EQUAL_INT(5, end);
}

void shouldFindCorrectlyTheInitAndTheEndOfASingleCharacter()
{
    char base_string[] = "Hello World";
    char keyword[] = " ";
    int ini, end;

    int result = idxof(base_string, keyword, &ini, &end);

    TEST_ASSERT_EQUAL_INT(FOUND, result);
    TEST_ASSERT_EQUAL_INT(5, ini);
    TEST_ASSERT_EQUAL_INT(6, end);
}

void shouldFindCorrectlyTheInitAndTheEndOfAString()
{
    char base_string[] = "Hello World";
    char keyword[] = "lo Wor";
    int ini, end;

    int result = idxof(base_string, keyword, &ini, &end);

    TEST_ASSERT_EQUAL(FOUND, result);
    TEST_ASSERT_EQUAL_INT(3, ini);
    TEST_ASSERT_EQUAL_INT(9, end);
}

int main()
{
    UNITY_BEGIN();

    RUN_TEST(shouldReturnZeroSearchingAWhitespace);
    RUN_TEST(shouldReturnZeroSearchingAString);
    RUN_TEST(shouldFindCorrectlyTheInitAndTheEndOfASingleCharacter);
    RUN_TEST(shouldFindCorrectlyTheInitAndTheEndOfAString);

    return UNITY_END();
}