# ifndef _STRING_UTILS_H_
# define _STRING_UTILS_H_

typedef struct str_list {
    char *string;
    struct str_list *next;
} STR_LIST_NODE;

/*
 * This enum has the possible return values for the idxof or the idxof_reverse functions.
 */
enum idxof_results {
    SUCCESS = 0,
    FOUND = 0,
    NOT_FOUND = -1,
    INVALID_STRING = 2,
    INVALID_KEYWORD = 3,
    INVALID_INDEX = 4,
    INVALID_PADDED_LEN = 5
};

/*
 * Function to find the start and end position of a string.
 * string: The string where you are looking for.
 * keyword: The string which you are looking for.
 * start: Position where the first keyword occurrence starts. (Out parameter, you should pass it by reference)
 * end: Posistion where the first keyword occurrence ends. (Out parameter, you should pass it by reference)
 * return:
 *      0 if the keyword exists in the string.
 *      1 if the keyword does not.
 * Example:
 *     _____________________________________________________
 *    |                                                     |
 *    |H |E |L |L |O |  |W |O |R |L |D |  |H |E |L |L |O |\0|
 *    |0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |10|11|12|13|14|15|16|17|
 *    |_____________________________________________________|
 *
 * idxof("HELLO WORLD HELLO", "HELLO", &start, &end);
 * printf("start = %d\nend = %d", start, end);
 *
 * Output:
 * start = 0
 * end = 5
 */
int
idxof(char *string, char *keyword, int *start, int *end);


/*
 * Function to find the start and end position of a string starting from the end.
 * string: The string where you are looking for.
 * keyword: The string which you are looking for.
 * start: Position where the first keyword occurrence starts. (Out parameter, you should pass it by reference)
 * end: Posistion where the first keyword occurrence ends. (Out parameter, you should pass it by reference)
 * return:
 *      0 if the keyword exists in the string.
 *      1 if the keyword does not.
 * Example:
 *     _____________________________________________________
 *    |H |E |L |L |O |  |W |O |R |L |D |  |H |E |L |L |O |\0|
 *    |0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |10|11|12|13|14|15|16|17|
 *    |_____________________________________________________|
 *
 * idxof_reverse("HELLO WORLD HELLO", "HELLO", &start, &end);
 * printf("start = %d\nend = %d", start, end);
 *
 * Output:
 * start = 12
 * end = 16
 */
int
idxof_reverse(char *string, char *keyword, int *start, int *end);


/*
 * This function return a piece of an string which starts and ends at the
 * given parameters.
 * string: The string you will extract your substring from.
 * ini: The position where your substring starts.
 * end: The position where your substring ends.
 * return:
 *      A string with the characters of the given string from "ini" till "end" position.
 */
int
substr(char *dest, char *string, int ini, int end);


/*
 * This function replaces all the occurrences of a string from another string for another string, you know.
 * string: the base string.
 * oldChar: the string wich you want replace from the base string.
 * newChar: the string which you want instead of the oldChar.
 */
int
replace(char *dest, char *string, char *oldChar, char *newChar);


/*
 * This function, as the name suggests, pads the right side of a given string with padString until the string length
 * reaches the paddedLength.
 * If the paddedLength is zero or negative your program will exit with 1 and prints a error message.
 * If the length of the string is actually equal or greater than the paddedLength the function will just
 * return the given string as it is.
 * string: the base string.
 * padString: the string with wich the base string will be padded. The padString will be truncated if the length of the
 * string reaches the paddedLength.
 * paddedLength: the length wich the final padded string must have.
 */
int
rpad(char *dest, char *string, char *padString, int paddedLength);


/*
 * This function iterate every node of the given single linked list
 * freeing the allocated memory.
 * head: The first node of the single linked list.
 */
void
free_str_list(STR_LIST_NODE *head);


/*
 * This function insert in the first position of the given single linked
 * list a new STR_LIST_NODE element.
 * head: The first node of the list.
 * new: The node to be inserted.
 * This function return a STR_LIST_NODE for the first node of the list,
 * which will be the new element.
 */
STR_LIST_NODE *
insert_str_list_node(STR_LIST_NODE *head, STR_LIST_NODE *new);


/*
 * This function initialize and return a pointer to a STR_LIST_NODE with the
 * value of the given string.
 */
STR_LIST_NODE *
new_str_list_node(char *string);


/*
 * This function split a string in every occurrence of a given delimiter.
 * string: The string which will be splited.
 * delimiter: the delimiter where the string will be splited.
 * The return of this function is a STR_LIST_NODE struct, which is the head
 * of a single linked list.
 * If there is not any occurrence of delimiter in string, then the function
 * will return NULL.
 */
STR_LIST_NODE *
str_split(char *string, char *delimiter);

# endif