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
gcc -c tests/idxofTests.c -Wall -pedantic -lm -std=c99
gcc -c tests/idxof_reverseTests.c -Wall -pedantic -lm -std=c99
gcc -c tests/replaceTests.c -Wall -pedantic -lm -std=c99
gcc -c tests/substrTests.c -Wall -pedantic -lm -std=c99
gcc -c tests/rpadTests.c -Wall -pedantic -lm -std=c99
gcc -c tests/splitTests.c -Wall -pedantic -lm -std=c99

# Link tests
gcc -o idxofTests idxofTests.o string-utils.o unity.o
gcc -o idxof_reverseTests idxof_reverseTests.o string-utils.o unity.o
gcc -o replaceTests replaceTests.o string-utils.o unity.o
gcc -o substrTests substrTests.o string-utils.o unity.o
gcc -o rpadTests rpadTests.o string-utils.o unity.o
gcc -o splitTests splitTests.o string-utils.o unity.o

trap 'echo "TESTS FAILED DUE TO SEGMENTATION FAULT. GO CHECK YOUR CODE!!!"; exit 1' ERR SIGSEGV

# Run tests
./idxofTests
if [[ "$(./idxofTests)" =~ "FAIL" ]]
then
    exit 1
fi


./idxof_reverseTests
if [[ "$(./idxof_reverseTests)" =~ "FAIL" ]]
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
    ./splitTests | cat
    exit 1
fi

clean_directory
