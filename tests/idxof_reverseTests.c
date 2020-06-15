# include "../src/string-utils.h"
# include "unity/unity.h"

void
shouldReturnFoundSearchingAWhitespace()
{
    char baseString[] = "Hello World";
    char keyword[] = " ";
    int ini, end;

    int result = idxof_reverse(baseString, keyword, &ini, &end);

    TEST_ASSERT_EQUAL_INT(FOUND, result);
    TEST_ASSERT_EQUAL_INT(5, ini);
    TEST_ASSERT_EQUAL_INT(6, end);
}

void
shouldReturnZeroSearchingAString()
{
    char baseString[] = "Hello World";
    char keyword[] = "Hello";
    int ini, end;

    int result = idxof_reverse(baseString, keyword, &ini, &end);

    TEST_ASSERT_EQUAL_INT(FOUND, result);
    TEST_ASSERT_EQUAL_INT(0, ini);
    TEST_ASSERT_EQUAL_INT(5, end);
}

void
shouldReturnOneSearchingASingleCharacter()
{
    char baseString[] = "Lorem Ipsum Dolor Sit Amet";
    char keyword[] = "Y";
    int ini, end;

    int result = idxof_reverse(baseString, keyword, &ini, &end);

    TEST_ASSERT_EQUAL_INT(NOT_FOUND, result);
}

void
shouldReturnOneSearchingAString()
{
    char baseString[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit";
    char keyword[] = "I don't speak latin";
    int ini, end;

    int result = idxof_reverse(baseString, keyword, &ini, &end);

    TEST_ASSERT_EQUAL_INT(NOT_FOUND, result);
}

void
shouldFindCorrectlyTheInitAndTheEndOfASingleCharacter()
{
    char baseString[] = "Test test test";
    char keyword[] = " ";
    int ini, end;

    int result = idxof_reverse(baseString, keyword, &ini, &end);

    TEST_ASSERT_EQUAL_INT(FOUND, result);
    TEST_ASSERT_EQUAL_INT(9, ini);
    TEST_ASSERT_EQUAL_INT(10, end);
}

void
shouldFindCorrectlyTheInitAndTheEndOfAString()
{
    char baseString[] = "Test test test";
    char keyword[] = "test";
    int ini, end;

    int result = idxof_reverse(baseString, keyword, &ini, &end);

    TEST_ASSERT_EQUAL_INT(FOUND, result);
    TEST_ASSERT_EQUAL_INT(10, ini);
    TEST_ASSERT_EQUAL_INT(14, end);
}

int
main()
{
    UNITY_BEGIN();

    RUN_TEST(shouldReturnFoundSearchingAWhitespace);
    RUN_TEST(shouldReturnZeroSearchingAString);
    RUN_TEST(shouldReturnOneSearchingASingleCharacter);
    RUN_TEST(shouldReturnOneSearchingAString);
    RUN_TEST(shouldFindCorrectlyTheInitAndTheEndOfASingleCharacter);
    RUN_TEST(shouldFindCorrectlyTheInitAndTheEndOfAString);

    return UNITY_END();
}