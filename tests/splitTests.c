# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "../src/string-utils.h"
# include "./unity/unity.h"

void sumOfSquaresTest()
{
    int sumOfSquares = 0;
    char string[] = "2; 3; 4"; /* 2*2 + 3*3 + 4*4 = 29*/
    STR_LIST_NODE *str_list_head = str_split(string, "; "), *currentNode = NULL;

    currentNode = str_list_head;
    while(currentNode)
    {
        int integer = atoi(currentNode->string);
        sumOfSquares = sumOfSquares + integer * integer;

        currentNode = currentNode->next;
    }

    free_str_list(str_list_head);
    TEST_ASSERT_EQUAL_INT(29, sumOfSquares);
}

int main(int argc, char *argv[])
{
    UNITY_BEGIN();

    RUN_TEST(sumOfSquaresTest);

    return UNITY_END();
}