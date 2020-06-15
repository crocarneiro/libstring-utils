# ifndef _STRING_UTILS_H_
# define _STRING_UTILS_H_

typedef struct str_list {
    char *string;
    struct str_list *next;
} STR_LIST_NODE;

enum functions_possible_results {
    SUCCESS,
    FOUND,
    NOT_FOUND,
    NOTHING_CHANGED,
    VALID_PARAMS,
    INVALID_STRING,
    INVALID_KEYWORD,
    INVALID_INDEX,
    INVALID_PADDED_LEN,
    INVALID_PAD_STRING
};

/*
 * Function to find the start and end position of a string.
 * string: The string where you are looking for.
 * keyword: The string which you are looking for.
 * start: Position where the first keyword occurrence starts. (Out parameter, you should pass it by reference)
 * end: Posistion where the first keyword occurrence ends. (Out parameter, you should pass it by reference)
 * return:
 *      FOUND if the keyword exists in the string.
 *      NOT_FOUND if the keyword does not exists in the string.
 *      INVALID_STRING if the string length is zero.
 *      INVALID_KEYWORD if the keyword length is zero.
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
 *      FOUND if the keyword exists in the string.
 *      NOT_FOUND if the keyword does not exists in the string.
 *      INVALID_STRING if the string length is zero.
 *      INVALID_KEYWORD if the keyword length is zero.
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
 * dest: Buffer for the new string.
 * string: The string you will extract your substring from.
 * ini: The position where your substring starts.
 * end: The position where your substring ends.
 * return:
 *      SUCCESS if the the function run without errors.
 *      INVALID_STRING if the string length is zero.
 *      INVALID_INDEX if the ini or end are less than zero or if ini is greater than end.
 */
int
substr(char *dest, char *string, int ini, int end);


/*
 * This function replaces all the occurrences of a string from another string for another string, you know.
 * dest: Buffer for the new string.
 * string: the base string.
 * oldChar: The string wich you want replace from the base string.
 * newChar: The string which you want instead of the oldChar.
 * return:
 *      SUCCESS if the function run without errors.
 *
 */
int
replace(char *dest, char *string, char *oldChar, char *newChar);


/*
 * This function, as the name suggests, pads the right side of a given string with pad_string until the string length
 * reaches the padded_length.
 * If the padded_length is zero or negative your program will exit with 1 and prints a error message.
 * If the length of the string is actually equal or greater than the padded_length the function will just
 * copy the given string to dest and return NOTHING_CHANGED.
 * dest: Buffer for the new string.
 * string: The base string.
 * pad_string: The string with wich the base string will be padded. The pad_string will be truncated if the length of the
 * string reaches the padded_length.
 * padded_length: The length that the final padded string will have.
 *  _______________________________________________________________________________________
 * |                                                                                       |
 * | OBS: This padded_length is without the \0 char. So if you pass, for instance, 10,     |
 * | your dest buffer must have allocated at least 11 bytes of memory for it. Despite this,|
 * | this function does put the \0 at the end of the dest, but if you do not have enough   |
 * | memory then an UNEXPECTED BEHAVIOUR MAY OCCUR.                                        |
 * |_______________________________________________________________________________________|
 * return:
 *      SUCCESS if the function run without erros.
 *      INVALID_STRING if the string length is zero.
 *      INVALID_PAD_STRING if the pad_string length is zero.
 *      INVALID_PADDED_LEN if the padded_length is less than zero.
 *      NOTHING_CHANGED if the string length is actually equal or greater than padded_length.
 */
int
rpad(char *dest, char *string, char *pad_string, int padded_length);


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