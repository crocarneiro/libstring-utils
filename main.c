#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void validateIndexOfParams(char *string, char *keyword)
{
    if (strlen(string) == 0 && string[0] == '\0')
    {
        fprintf(stderr, "You should pass a string for search.\n");
        exit(1);
    }

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

                return 0;
            }

            j++;
        }
        else
        {
            checkpoint = 0;
            j = 0;
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
}

char *substr(char *string, int ini, int end)
{
    char *newString = (char *)malloc(sizeof(char) * (end - ini));
    int i, j = 0;

    validateSubstrParams(string, ini, end);

    for(i = ini; i <= end; i++)
    {
        newString[j] = string[i];
        j++;
    }

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

    do
    {
        if(indexOf(string, oldChar, &ini, &end) == 0)
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
                strcat(newString, substr(string, 0, ini - 1));
                strcat(newString, newChar);

                if(end != stringLen - 1)
                    strcat(newString, substr(string, end, stringLen));
            }

            count++;
        }
        else
        {
            return string;
        }
    } while(indexOf(newString, oldChar, &ini, &end) == 0);

    if(count == 0)
        return string;
    else
        return newString;
}

int main(int argc, char *argv[])
{
    int ini, end;

    indexOf("Hello world.", " w", &ini, &end);
    printf("Ini: %d.\n", ini);
    printf("End: %d.\n", end);
    printf("%s\n\n", substr("Hello World", 5, 10));
    printf("%s\n", replace("Hello Mundo", "Mundo", "World"));
    printf("%s\n", replace("(% 1", "% 1", " %1"));
    printf("%s\n\n", replace("( %1", " ( %1", "(%1"));

    return 0;
}