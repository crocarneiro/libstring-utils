# include "../src/string-utils.h"
# include "unity/unity.h"

void shouldReturnZeroSearchingAWhitespace()
{
    char baseString[] = "Hello World";
    char keyword[] = " ";
    int ini, end;
    TEST_ASSERT_EQUAL_INT(0, idxof(baseString, keyword, &ini, &end));
}

void shouldReturnZeroSearchingAString()
{
    char baseString[] = "Hello World";
    char keyword[] = "Hello";
    int ini, end;
    TEST_ASSERT_EQUAL_INT(0, idxof(baseString, keyword, &ini, &end));
}

void shouldFindCorrectlyTheInitAndTheEndOfASingleCharacter()
{
    char baseString[] = "Hello World";
    char keyword[] = " ";
    int ini, end;

    idxof(baseString, keyword, &ini, &end);
    TEST_ASSERT_EQUAL_INT(5, ini);
    TEST_ASSERT_EQUAL_INT(6, end);
}

void shouldFindCorrectlyTheInitAndTheEndOfAString()
{
    char baseString[] = "Hello World";
    char keyword[] = "lo Wor";
    int ini, end;

    idxof(baseString, keyword, &ini, &end);
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