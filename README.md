[![ko-fi](https://www.ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/X8X41FYY7)

# Index
* [About](#About)
* [Installation](#Installation)

# About

I remember when I was searching for a simple way to do a replace with string in C. I just wanted to pass `char*` parameters and get as a result another `char*`, but all the libraries I found requested me to use some struct as string. That's why I created **libstring-utils**.

With libstring-utils it's all play and fun, BUT BE CAREFUL:

> THE MEMORY FOR THE RETURN OF THE FUNCTIONS IS ALREADY
> ALLOCATED INSIDE THE FUNCTIONS, SO YOU NEED TO
> REMEMBER TO `FREE()` THE RESULT WHEN YOU DON'T NEED IT
> ANYMORE

<br />
<br />
CURRENTLY THE LIBSTRING-UTILS HAS THE FOLLOWING TYPES:

* [STR_LIST_NODE](#STR_LIST_NODE)

## STR_LIST_NODE
This type represents a node of a single linked list. With this type you can create and manage a single linked list of strings.
To make things easier you can use the function [new_str_list_node](#new_str_list_node) to initialize a new "instance" of `STR_LIST_NODE`. THIS FUNCTION WILL ALLOCATE THE MEMORY NECESSARY. To insert a new node in the list you can use the function [insert_str_list_node](#insert_str_list_node). WHEN YOU DO NOT NEED THE LIST ANYMORE, REMEMBER TO FREE THE MEMORY USING THE FUNCTION [free_str_list](#free_str_list). For a full example of usage check the function [str_split](#str_split) out.

<br />
<br />
CURRENTLY THE LIBSTRING-UTILS HAS THE FOLLOWING FUNCTIONS:

* [free_str_list](#free_str_list)
* [indexOf](#indexOf)
* [indexOfReverse](#indexOfReverse)
* [insert_str_list_node](#insert_str_list_node)
* [new_str_list_node](#new_str_list_node)
* [replace](#replace)
* [rpad](#rpad)
* [str_split](#str_split)
* [substr](#substr)

## free_str_list
This function iterate every node of the given single linked list freeing the allocated memory.

#### Prototype:
```c
void free_str_list(STR_LIST_NODE *head);
```

`head`: The first node of the single linked list.

## indexOf
Function to find the start and end position of a string.

#### Prototype:
```c
int indexOf(char *string, char *keyword, int *start, int *end);
```

`string`: The string where you are looking for.

`keyword`: The string which you are looking for.

`start`: Position where the first keyword occurrence starts. (Out parameter, you should pass it by reference)

`end`: Posistion where the first keyword occurrence ends. (Out parameter, you should pass it by reference)

#### Return:
> 0 if the keyword exists in the string.

> 1 if the keyword does not.

## indexOfReverse
Function to find the start and end position of a string starting from the end.

#### Prototype:
```c
int indexOfReverse(char *string, char *keyword, int *start, int *end);
```

Function to find the start and end position of a string starting from the end.
`string`: The string where you are looking for.

`keyword`: The string which you are looking for.

`start`: Position where the first keyword occurrence starts. (Out parameter, you should pass it by reference)

`end`: Posistion where the first keyword occurrence ends. (Out parameter, you should pass it by reference)

 #### Return:
 > 0 if the keyword exists in the string.

 > 1 if the keyword does not.

## insert_str_list_node
This function insert in the first position of the given single linked list a new STR_LIST_NODE element.

#### Prototype:
```c
STR_LIST_NODE *insert_str_list_node(STR_LIST_NODE *head, STR_LIST_NODE *new);
```

`head`: The first node of the list.

`new`: The node to be inserted.

#### Return:
> This function return a STR_LIST_NODE for the first node of the list, which will be the new element.

#### Usage Example:
For a full example of usage of this function check the function [str_split](#str_split) out.

## new_str_list_node
This function initialize and return a pointer to a `STR_LIST_NODE` with the value of the given string.

#### Prototype:
```c
STR_LIST_NODE *new_str_list_node(char *string);
```

#### Usage Example:
For a full example of usage of this function check the function [str_split](#str_split) out.

## replace
This function replaces all the occurrences of a string from other string for another string.

#### Prototype:
```c
char *replace(char *string, char *oldChar, char *newChar);
```

`oldChar`: the string wich you want replace from the base string.

`newChar`: the string which you want instead of the oldChar.

#### Return:
> New string with all the occurrences of `oldChar` replaced by `newChar`.

## rpad
This function, as the name suggests, pads the right side of a given string with padString until the string length reaches the paddedLength.

If the paddedLength is zero or negative your program will exit with 1 and prints a error message.

If the length of the string is actually equal or greater than the paddedLength the function will just return the given string as it is.

#### Prototype:
```c
char *rpad(char *string, char *padString, int paddedLength);
```

`string`: the base string.

`padString`: the string with wich the base string will be padded. The padString will be truncated if the length of the string reaches the paddedLength.

`paddedLength`: the length wich the final padded string must have.

#### Return:
> The padded string.

## str_split
This function split a string in every occurrence of a given delimiter.

#### Prototype:
```c
STR_LIST_NODE *str_split(char *string, char *delimiter);
```

`string`: The string which will be splited.

#### Return:
> The return of this function is a `STR_LIST_NODE` struct, which is the head of a single linked list.

> If there is not any occurrence of delimiter in string, then the function will return `NULL`.

#### Usage Example:
The following program split the string "2; 3; 4" in every occurrence of "; " in order to sum the squares of the integers.
```c
int main(int argc, char *argv[])
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
    printf("Sum of squares: %d\n", sumOfSquares);

    //REMEMBER TO FREE THE MEMORY ALLOCATED
    free_str_list(str_list_head);

    return 0;
}
```

## substr
This function return a piece of an string which starts and ends at the given parameters.

#### Prototype:
```c
char *substr(char *string, int ini, int end);
```

`ini`: The position where your substring starts.

`end`: The position where your substring ends.

#### Return:
> A string with the characters of the given string from "ini" till "end" position.

# Installation

## Clone this repository

`git clone https://github.com/crocarneiro/libstring-utils`

and move into the repo

`cd libstring-utils`

make sure you've build-essential install

* On ubuntu: `sudo apt-get install build-essential`
* On Archlinux: `yay build-essential`

Run autotools:

`autoreconf --install`

and run:
```sh
./configure
# Run the unit tests to make sure you have a stable version
make check
make
sudo make install
```