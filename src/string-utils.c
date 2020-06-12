#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string-utils.h"


int
chk_idxof_prms(char *string, char *keyword)
{
    if (strlen(keyword) == 0 && keyword[0] == '\0')
        return INVALID_KEYWORD;

    if (strlen(string) == 0 && string[0] == '\0')
        return INVALID_STRING;

    return 0;
}

/*
 * This algorithm has the following logic:
 * -> Iterate all the characters of string testing if the current char matches the first char of the keyword.
 * -> If it does then store this position in a variable. This variable will be a "checkpoint".
 * --> Then we check if the next char of the string matches the second char of the keyword.
 * ---> If it does, we continue the same pattern checking the next chars until the current char
 * of string matches the last char of the keyword. When the execution reach this point
 * we assign the "checkpoint" variable value to the "start" parameter and the current position
 * to the "end" parameter. The execution of the function ends here returning zero.
 * ---> If it does not then we reset the checkpoint and go back checking if the
 * current char of string matches the first char of the keyword.
 */
int
idxof(char *string, char *keyword, int *start, int *end)
{
    int i, j = 0;                             /* Loop indexes */
    int checkpoint = 0;                       /* The string position which matches the first char of keyword */
    int stringLength = strlen(string);        /* The length of the string */
    int keywordLength = strlen(keyword) - 1;  /* The length of the keyword minus one (The -1 is important) */

    if(chk_idxof_prms(string, keyword) != 0)
        return chk_idxof_prms(string, keyword);

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

                return FOUND;
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

                    return FOUND;
                }

                j++;
            }
        }
    }

    return NOT_FOUND;
}

/*
 * For a detailed explanation of how this function works, read the comment above
 * the idxof function. This function has the same logic, the only difference is
 * that this one runs backwards.
 */
int
idxof_reverse(char *string, char *keyword, int *start, int *end)
{
    int checkpoint = 0;                  /* The string position which matches the first char of keyword */
    int keywordLength = strlen(keyword); /* The length of the keyword */
    int stringLength = strlen(string);   /* The length of the string */
    int i, j = keywordLength - 1;        /* Loop indexes (the -1 in the j is important) */

    if(chk_idxof_prms(string, keyword) != 0)
        return chk_idxof_prms(string, keyword);

    if(idxof(string, keyword, NULL, NULL) != FOUND)
        return idxof(string, keyword, NULL, NULL);

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

                return FOUND;
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

                    return FOUND;
                }

                j--;
            }
        }
    }

    return NOT_FOUND;
}


int
chk_substr_prms(char *string, int ini, int end)
{
    if(strlen(string) == 0 && string[0] == '\0')
        return INVALID_STRING;

    if(ini < 0 || end < 0 || ini > end)
        return INVALID_INDEX;

    return 0;
}

int
substr(char *dest, char *string, int ini, int end)
{
    int i, j = 0;

    if(chk_substr_prms(string, ini, end) != 0)
        return chk_substr_prms(string, ini, end);

    for(i = ini; i < end; i++)
    {
        dest[j] = string[i];
        j++;
    }
    dest[j] = '\0';

    return 0;
}


int
replace(char *dest, char *string, char *oldChar, char *newChar)
{
    int ini, end, count = 0;
    int stringLen = strlen(string);

    if(idxof(string, oldChar, &ini, &end) != 0)
    {
        strcpy(dest, string);
        return SUCCESS;
    }

    do
    {
        if(ini == 0)
        {
            strcat(dest, newChar);
            char *aux = (char *) malloc(sizeof(char) * (stringLen - end + 1 ));
            substr(aux, string, end, stringLen);
            strcat(dest, aux);
            free(aux);
        }
        else
        {
            char *aux = (char *)malloc(sizeof(char) * ini);
            substr(aux, string, 0, ini);
            strcat(dest, aux);
            free(aux);
            strcat(dest, newChar);

            if(end != stringLen - 1)
            {
                aux = (char *) malloc(sizeof (char) * (stringLen - end + 1));
                substr(aux, string, end, stringLen);
                strcat(dest, aux);
                free(aux);
            }
        }

        count++;
    } while(idxof(dest, oldChar, &ini, &end) == 0);

    if (count == 0)
        strcpy(dest, string);

    return SUCCESS;
}


int
chk_rpad_prms(char *string, char *padString, int padded_length)
{
    if(padded_length <= 0)
        return INVALID_PADDED_LEN;

    if(strlen(string) >= padded_length)
        return INVALID_PADDED_LEN;

    return 0;
}


int
rpad(char *dest, char *string, char *padString, int paddedLength)
{
    if(chk_rpad_prms(string, padString, paddedLength) != 0)
        return chk_rpad_prms(string, padString, paddedLength);

    int n = strlen(string), i;
    while(strlen(dest) < paddedLength)
    {
        for(i = 0; i < strlen(padString); i++)
        {
            int actualSize = strlen(dest);
            if(actualSize == paddedLength) break;

            dest[n] = padString[i];
            n++;
        }
    }

    return SUCCESS;
}


STR_LIST_NODE *
insert_str_list_node(STR_LIST_NODE *head, STR_LIST_NODE *new)
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


STR_LIST_NODE *
new_str_list_node(char *string)
{
    STR_LIST_NODE *newNode = malloc(sizeof(STR_LIST_NODE));
    newNode->string = (char *) malloc(sizeof(strlen(string)));
    strcpy(newNode->string, string);

    return newNode;
}


void
free_str_list(STR_LIST_NODE *head)
{
    STR_LIST_NODE *currentNode = head;
    while(currentNode)
    {
        free(currentNode->string);
        currentNode = currentNode->next;
    }
}


STR_LIST_NODE *
str_split(char *string, char *delimiter)
{
    int start, end;
    char *currentString = (char *)malloc(sizeof(strlen(string)));
    STR_LIST_NODE *head = NULL;

    if(idxof(string, delimiter, &start, &end) == 1)
        return NULL;

    strcpy(currentString, string);
    while(idxof(currentString, delimiter, &start, &end) == 0)
    {
        char *newString = (char *) malloc(sizeof(char) * start);
        substr(newString, currentString, 0, start);

        STR_LIST_NODE *newNode = new_str_list_node(newString);
        head = insert_str_list_node(head, newNode);

        substr(currentString, currentString, end, strlen(currentString));
        //strcpy(currentString, substr(currentString, end, strlen(currentString)));
    }

    STR_LIST_NODE *newNode = new_str_list_node(currentString);
    head = insert_str_list_node(head, newNode);

    return head;
}