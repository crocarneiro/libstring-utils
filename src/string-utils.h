# ifndef _STRING_UTILS_H_
# define _STRING_UTILS_H_

/*
 * Function to find the start and end position of a string.
 * string: The string where you are looking for.
 * keyword: The string which you are looking for.
 * start: Position where the first keyword occurrence starts. (Out parameter, you should pass it by reference)
 * end: Posistion where the first keyword occurrence ends. (Out parameter, you should pass it by reference)
 * return:
 *      0 if the keyword exists in the string.
 *      1 if the keyword does not.
 */
int indexOf(char *string, char *keyword, int *start, int *end);

/*
 * Function to find the start and end position of a string starting from the end.
 * string: The string where you are looking for.
 * keyword: The string which you are looking for.
 * start: Position where the first keyword occurrence starts. (Out parameter, you should pass it by reference)
 * end: Posistion where the first keyword occurrence ends. (Out parameter, you should pass it by reference)
 * return:
 *      0 if the keyword exists in the string.
 *      1 if the keyword does not.
 */
int indexOfReverse(char *string, char *keyword, int *start, int *end);

/*
 * This function return a piece of an string which starts and ends at the
 * given parameters.
 * string: The string you will extract your substring from.
 * ini: The position where your substring starts.
 * end: The position where your substring ends.
 * return:
 *      A string with the characters of the given string from "ini" till "end" position.
 */
char *substr(char *string, int ini, int end);

/*
 * This function replaces all the occurrences of a string from another string for another string, you know.
 * string: the base string.
 * oldChar: the string wich you want replace from the base string.
 * newChar: the string which you want instead of the oldChar.
 */
char *replace(char *string, char *oldChar, char *newChar);

char *rpad(char *string, char *pad_string, int padded_length);

# endif