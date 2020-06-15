#include <stdlib.h>
#include "../src/string-utils.h"
#include "unity/unity.h"

void should_succeed_with_single_string()
{
    char base_string[] = "Hello Mundo";
    char *new_string = (char*) malloc(12);
    char old_char[] = "Mundo";
    char new_char[] = "World";
    int result;

    new_string[0] = '\0';
    result = replace(new_string, base_string, old_char, new_char);

    TEST_ASSERT_EQUAL_INT(SUCCESS, result);
    TEST_ASSERT_EQUAL_STRING("Hello World", new_string);

    free(new_string);
}

void should_succeed_with_single_whitespace()
{
    char base_string[] = "Hello World";
    char *new_string = (char*) malloc(12);
    char old_char[] = " ";
    char new_char[] = ";";
    int result;

    new_string[0] = '\0';
    result = replace(new_string, base_string, old_char, new_char);

    TEST_ASSERT_EQUAL_INT(SUCCESS, result);
    TEST_ASSERT_EQUAL_STRING("Hello;World", new_string);

    free(new_string);
}

void should_succeed_with_special_character()
{
    char base_string[] = "(%% 1";
    char *new_string = (char*) malloc(5);
    char old_char[] = "%% 1";
    char new_char[] = " %%1";
    int result;

    new_string[0] = '\0';
    result = replace(new_string, base_string, old_char, new_char);

    TEST_ASSERT_EQUAL_INT(SUCCESS, result);
    TEST_ASSERT_EQUAL_STRING("( %%1", new_string);

    free(new_string);
}

void should_succeed_with_special_character2()
{
    char base_string[] = "( %%1";
    char *new_string = (char*) malloc(4);
    new_string[0] = '\0';
    char old_char[] = "( %%";
    char new_char[] = "(%%";

    int result = replace(new_string, base_string, old_char, new_char);

    TEST_ASSERT_EQUAL_INT(SUCCESS, result);
    TEST_ASSERT_EQUAL_STRING("(%%1", new_string);

    free(new_string);
}

void should_succeed_with_special_character3()
{
    char base_string[] = "Sintonizando títulos (%%1/%% 2).";
    char *new_string = (char*) malloc(31);
    char old_char[] = "%% 2";
    char new_char[] = "%%2";
    int result;

    new_string[0] = '\0';
    result = replace(new_string, base_string, old_char, new_char);

    TEST_ASSERT_EQUAL_INT(SUCCESS, result);
    TEST_ASSERT_EQUAL_STRING("Sintonizando títulos (%%1/%%2).", new_string);

    free(new_string);
}

int main()
{
    UNITY_BEGIN();

    RUN_TEST(should_succeed_with_single_string);
    RUN_TEST(should_succeed_with_single_whitespace);
    RUN_TEST(should_succeed_with_special_character);
    RUN_TEST(should_succeed_with_special_character2);
    RUN_TEST(should_succeed_with_special_character3);

    return UNITY_END();
}