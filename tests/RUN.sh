clean_directory()
{
    if [ -e string-utils.o ]
    then
        rm string-utils.o
    fi

    if [ -e unity.o ]
    then
        rm unity.o
    fi

    if [ -e indexOfTests.o ]
    then
        rm indexOfTests.o
    fi

    if [ -e indexOfTests ]
    then
        rm indexOfTests
    fi

    if [ -e indexOfReverseTests.o ]
    then
        rm indexOfReverseTests.o
    fi

    if [ -e indexOfReverseTests ]
    then
        rm indexOfReverseTests
    fi

    if [ -e replaceTests.o ]
    then
        rm replaceTests.o
    fi

    if [ -e replaceTests ]
    then
        rm replaceTests
    fi

    if [ -e substrTests.o ]
    then
        rm substrTests.o
    fi

    if [ -e substrTests ]
    then
        rm substrTests
    fi

    if [ -e splitTests ]
    then
        rm splitTests
    fi
}

clean_directory

# Compile dependencies
gcc -c src/string-utils.c -Wall -pedantic -lm -std=c99
gcc -c tests/unity/unity.c -Wall -pedantic -lm -std=c99

# Compile tests
gcc -c tests/indexOfTests.c -Wall -pedantic -lm -std=c99
gcc -c tests/indexOfReverseTests.c -Wall -pedantic -lm -std=c99
gcc -c tests/replaceTests.c -Wall -pedantic -lm -std=c99
gcc -c tests/substrTests.c -Wall -pedantic -lm -std=c99
gcc -c tests/rpadTests.c -Wall -pedantic -lm -std=c99
gcc -c tests/splitTests.c -Wall -pedantic -lm -std=c99

# Link tests
gcc -o indexOfTests indexOfTests.o string-utils.o unity.o
gcc -o indexOfReverseTests indexOfReverseTests.o string-utils.o unity.o
gcc -o replaceTests replaceTests.o string-utils.o unity.o
gcc -o substrTests substrTests.o string-utils.o unity.o
gcc -o rpadTests rpadTests.o string-utils.o unity.o
gcc -o splitTests splitTests.o string-utils.o unity.o

# Run tests
./indexOfTests
if [[ "$(./indexOfTests)" =~ "FAIL" ]]
then
    exit 1
fi

./indexOfReverseTests
if [[ "$(./indexOfReverseTests)" =~ "FAIL" ]]
then
    exit 1
fi

./replaceTests
if [[ "$(./replaceTests)" =~ "FAIL" ]]
then
    exit 1
fi

./substrTests
if [[ "$(./substrTests)" =~ "FAIL" ]]
then
    exit 1
fi

./rpadTests
if [[ "$(./rpadTests)" =~ "FAIL" ]]
then
    exit 1
fi

./splitTests
if [[ "$(./splitTests)" =~ "FAIL" ]]
then
    exit 1
fi

clean_directory
