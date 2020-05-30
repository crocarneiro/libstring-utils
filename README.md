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

Currently the libstring-utils has the following functions:

* [indexOf](#indexOf)
* [indexOfReverse](#indexOfReverse)
* [replace](#replace)
* [rpad](#rpad)
* [substr](#substr)

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