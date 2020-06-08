#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string-utils.h"

void validateIndexOfParams(char *string, char *keyword)
{
    if (strlen(keyword) == 0 && keyword[0] == '\0')
    {
        fprintf(stderr, "You should pass a keyword for search.\n");
        exit(1);
    }
}

int indexOf(char *string, char *keyword, int *start, int *end)
{
    int i, j = 0, checkpoint = 0;
    int stringLength = strlen(string);
    int keywordLength = strlen(keyword) - 1;

    validateIndexOfParams(string, keyword);

    if (strlen(string) == 0 && string[0] == '\0')
        return 1;

    for (i = 0; i <= stringLength; i++)
    {
        if (string[i] == keyword[j])
        {
            if (j == 0)
                checkpoint = i;

            if (j == keywordLength)
            {
                *start = checkpoint;
                *end = i;
                *end = *end + 1;

                return 0;
            }

            j++;
        }
        else
        {
            checkpoint = 0;
            j = 0;

            if (string[i] == keyword[j])
            {
                if (j == 0)
                    checkpoint = i;

                if (j == keywordLength)
                {
                    *start = checkpoint;
                    *end = i;
                    *end = *end + 1;

                    return 0;
                }

                j++;
            }
        }
    }

    return 1;
}

int indexOfReverse(char *string, char *keyword, int *start, int *end)
{
    int checkpoint, keywordLength = strlen(keyword), stringLength = strlen(string);
    int i, j = keywordLength - 1;
    int dummyStart, dummyEnd;

    validateIndexOfParams(string, keyword);

    if(indexOf(string, keyword, &dummyStart, &dummyEnd) == 1)
        return 1;

    for(i = stringLength - 1; i >= 0; i--)
    {
        if(string[i] == keyword[j])
        {
            if(j == keywordLength - 1)
                checkpoint = i;

            if(j == 0)
            {
                *end = checkpoint + 1;
                *start = i;

                return 0;
            }

            j--;
        }
        else
        {
            j = keywordLength - 1;
            checkpoint = 0;

            if(string[i] == keyword[j])
            {
                if(j == keywordLength)
                    checkpoint = i;

                if(j == 0)
                {
                    *end = checkpoint;
                    *start = i;

                    return 0;
                }

                j--;
            }
        }
    }

    return 1;
}

void validateSubstrParams(char *string, int ini, int end)
{
    if(strlen(string) == 0 && string[0] == '\0')
    {
        fprintf(stderr, "You should pass a valid string to substr.");
        exit(1);
    }

    if(ini < 0 || end < 0)
    {
        fprintf(stderr, "The position parameters cannot be negative.");
        exit(1);
    }

    if(ini > end)
    {
        fprintf(stderr, "The start position cannot be greater than the end position.");
        exit(1);
    }
}

char *substr(char *string, int ini, int end)
{
    int i, j = 0;
    char *newString = (char *)malloc(sizeof(char) * (end - ini));
    strcpy(newString, "\0");

    validateSubstrParams(string, ini, end);

    for(i = ini; i < end; i++)
    {
        newString[j] = string[i];
        j++;
    }
    newString[j] = '\0';

    return newString;
}

char *replace(char *string, char *oldChar, char *newChar)
{
    int ini, end, count = 0;
    int oldCharLen = strlen(oldChar);
    int newCharLen = strlen(newChar);
    int stringLen = strlen(string);
    int newStringLen = stringLen + (oldCharLen - newCharLen);
    char *newString = (char *) malloc(sizeof(char) * newStringLen);
    strcpy(newString, "\0");

    if(indexOf(string, oldChar, &ini, &end) != 0)
        return string;

    do
    {
        if(count > 0)
            newString = (char *) realloc(newString, sizeof(char) * (newStringLen + (oldCharLen - newCharLen)));

        if(ini == 0)
        {
            strcat(newString, newChar);
            strcat(newString, substr(string, end, stringLen));
        }
        else
        {
            strcat(newString, substr(string, 0, ini));
            strcat(newString, newChar);

            if(end != stringLen - 1)
                strcat(newString, substr(string, end, stringLen));
        }

        count++;
    } while(indexOf(newString, oldChar, &ini, &end) == 0);

    return (count == 0) ? string : newString;
}

void validatePaddedLength(int paddedLentgh)
{
    if(paddedLentgh <= 0)
    {
        puts("The padded length cannot be zero or negative.");
        exit(1);
    }
}

char *rpad(char *string, char *padString, int paddedLength)
{
    validatePaddedLength(paddedLength);

    if(strlen(string) >= paddedLength) return string;

    char *paddedString = (char *) malloc(sizeof(char) * paddedLength);
    strcpy(paddedString, string);

    int n = strlen(string), i;
    while(strlen(paddedString) < paddedLength)
        for(i = 0; i < strlen(padString); i++)
        {
            int actualSize = strlen(paddedString);
            if(actualSize == paddedLength) break;

            paddedString[n] = padString[i];
            n++;
        }

    return paddedString;
}

STR_LIST_NODE *insert_str_list_node(STR_LIST_NODE *head, STR_LIST_NODE *new)
{
    if(head == NULL)
    {
        head = new;
        head->next = NULL;
    }
    else
    {
        STR_LIST_NODE *previous = head;
        head = new;
        head -> next = previous;
    }

    return head;
}

STR_LIST_NODE *new_str_list_node(char *string)
{
    STR_LIST_NODE *newNode = malloc(sizeof(STR_LIST_NODE));
    newNode->string = (char *) malloc(sizeof(strlen(string)));
    strcpy(newNode->string, string);

    return newNode;
}

void free_str_list(STR_LIST_NODE *head)
{
    STR_LIST_NODE *currentNode = head;
    while(currentNode)
    {
        free(currentNode->string);
        currentNode = currentNode->next;
    }
}

STR_LIST_NODE *str_split(char *string, char *delimiter)
{
    int start, end;
    char *currentString = (char *)malloc(sizeof(strlen(string)));
    STR_LIST_NODE *head = NULL;

    if(indexOf(string, delimiter, &start, &end) == 1)
        return NULL;

    strcpy(currentString, string);
    while(indexOf(currentString, delimiter, &start, &end) == 0)
    {
        char *newString = substr(currentString, 0, start);
        STR_LIST_NODE *newNode = new_str_list_node(newString);
        head = insert_str_list_node(head, newNode);

        strcpy(currentString, substr(currentString, end, strlen(currentString)));
    }

    STR_LIST_NODE *newNode = new_str_list_node(currentString);
    head = insert_str_list_node(head, newNode);

    return head;
}