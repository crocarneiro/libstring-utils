#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indexOf(char *string, char *keyword, int *start, int *end)
{
    int i, j = 0, checkpoint = 0;
    int stringLength = strlen(string);
    int keywordLength = strlen(keyword) - 1;

    if (stringLength == 0 || string[0] == '\0')
    {
        fprintf(stderr, "You should pass a string for search.\n");
        exit(1);
    }

    if (keywordLength == 0 || keyword[0] == '\0')
    {
        fprintf(stderr, "You should pass a keyword for search.\n");
        exit(1);
    }

    for (i = 0; i <= stringLength; i++)
    {
        printf("%c == %c\n", string[i], keyword[j]);
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

int main(int argc, char *argv[])
{
    int ini, end;

    indexOf("Hello world.", "", &ini, &end);
    printf("Ini: %d.\n", ini);
    printf("End: %d.\n", end);

    return 0;
}