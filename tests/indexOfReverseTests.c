# include "../src/string-utils.h"
# include "unity/unity.h"

void shouldReturnZeroSearchingAWhitespace()
{
    char baseString[] = "Hello World";
    char keyword[] = " ";
    int ini, end;

    TEST_ASSERT_EQUAL_INT(0, indexOfReverse(baseString, keyword, &ini, &end));
}

void shouldReturnZeroSearchingAString()
{
    char baseString[] = "Hello World";
    char keyword[] = "Hello";
    int ini, end;

    TEST_ASSERT_EQUAL_INT(0, indexOfReverse(baseString, keyword, &ini, &end));
}

void shouldReturnOneSearchingASingleCharacter()
{
    char baseString[] = "Lorem Ipsum Dolor Sit Amet";
    char keyword[] = "Y";
    int ini, end;

    TEST_ASSERT_EQUAL_INT(1, indexOfReverse(baseString, keyword, &ini, &end));
}

void shouldReturnOneSearchingAString()
{
    char baseString[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit";
    char keyword[] = "I don't speak latin";
    int ini, end;

    TEST_ASSERT_EQUAL_INT(1, indexOfReverse(baseString, keyword, &ini, &end));
}

void shouldFindCorrectlyTheInitAndTheEndOfASingleCharacter()
{
    char baseString[] = "Test test test";
    char keyword[] = " ";
    int ini, end;

    indexOfReverse(baseString, keyword, &ini, &end);

    TEST_ASSERT_EQUAL_INT(9, ini);
    TEST_ASSERT_EQUAL_INT(10, end);
}

void shouldFindCorrectlyTheInitAndTheEndOfAString()
{
    char baseString[] = "Test test test";
    char keyword[] = "test";
    int ini, end;

    indexOfReverse(baseString, keyword, &ini, &end);

    TEST_ASSERT_EQUAL_INT(10, ini);
    TEST_ASSERT_EQUAL_INT(14, end);
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(shouldReturnZeroSearchingAWhitespace);
    RUN_TEST(shouldReturnZeroSearchingAString);
    RUN_TEST(shouldReturnOneSearchingASingleCharacter);
    RUN_TEST(shouldReturnOneSearchingAString);
    RUN_TEST(shouldFindCorrectlyTheInitAndTheEndOfASingleCharacter);
    RUN_TEST(shouldFindCorrectlyTheInitAndTheEndOfAString);
    return UNITY_END();
}