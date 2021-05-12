#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Lab4_1.h"

void isSomeCharTest() {
    assert(isLetter('G') == 1);
    assert(isLetter('1') == 0);
    assert(isLetter(' ') == 0);
    printf("\n\"Is letter\" test completed.");

    assert(isDigit('8') == 1);
    assert(isDigit('n') == 0);
    assert(isDigit('/') == 0);    
    printf("\n\"Is digit\" test completed.");
}

void lineLengthTest() {
    char *test = NULL;
    assert(lineLength("") == 0);
    assert(lineLength("FGrtyhihj ") == 10);
    assert(lineLength(test) == 0);
    printf("\n\"Line length\" test completed.");
}

void swapAndCompareStringsTest() {
    char *firstLine = NULL;
    char *secondLine = NULL;

    firstLine = (char *)malloc(10 * sizeof(char));
    if (!firstLine) return;

    secondLine = (char *)malloc(10 * sizeof(char));
    if (!secondLine) {
        free(firstLine);
        return;
    }

    /*first*/
    fgets(firstLine, 20, stdin);
    /*Well yes*/
    fgets(secondLine, 20, stdin);
    
    assert(compareStrings(firstLine, secondLine) > 0);

    swapStrings(&firstLine, &secondLine);

    assert(compareStrings(firstLine, secondLine) < 0);
    free(firstLine);
    free(secondLine);
    printf("\n\"Swap and compare strings\" test completed.");
}

void toLowerTest() {
    char *firstLine = NULL;
    char *secondLine = NULL;

    firstLine = (char *)malloc(13 * sizeof(char));
    if (!firstLine) return;

    secondLine = (char *)malloc(13 * sizeof(char));
    if (!secondLine) {
        free(firstLine);
        return;
    }

    /*ToLoWeRtEsT*/
    fgets(firstLine, 20, stdin);
    /*tolowertest*/
    fgets(secondLine, 20, stdin);

    assert(charToLower('A') == 'a');
    assert(charToLower('r') == 'r');
    assert(charToLower('4') == '4');
    assert(charToLower('/') == '/');

    stringToLower(firstLine);
    assert(compareStrings(firstLine, secondLine) == 0);

    free(firstLine);
    free(secondLine);
    printf("\n\"To lower\" test completed.");
}

void checkNULLTest() {
    int temp = 5;
    int *notNULLptr = &temp;

    printf("\nTest error message: ");
    assert(checkNULL(NULL) == 1);

    assert(checkNULL(notNULLptr) == 0);
    printf("\"Check NULL\" test completed.");
}

void finalTest() {
    char **text = NULL;
    char **separateWords = NULL;
    unsigned int linesNumber = 5, wordsNumber;

    text = getTwoDimensionalArray(linesNumber);
    getText(&text, &linesNumber);

    if (!text) return;

    assert(linesNumber == 3);
    
    wordsNumber = linesNumber * 10;

    assert(wordsNumber == 30);

    separateWords = getTwoDimensionalArray(wordsNumber);

    getSeparateWords(text, linesNumber, &separateWords, &wordsNumber);
    if (!separateWords) return;

    assert(wordsNumber == 12);

    textToLower(separateWords, wordsNumber);

    sortAlphabetically(separateWords, wordsNumber);
    printf("\nSorted version of words");
    printArray(separateWords, wordsNumber);

    countAmountOfWords(separateWords, wordsNumber);
    
    assert(occursWord(separateWords, wordsNumber, separateWords[0]) == 1);
    assert(occursWord(separateWords, wordsNumber, separateWords[1]) == 1);
    assert(occursWord(separateWords, wordsNumber, separateWords[2]) == 1);
    assert(occursWord(separateWords, wordsNumber, separateWords[3]) == 1);
    assert(occursWord(separateWords, wordsNumber, separateWords[4]) == 1);
    assert(occursWord(separateWords, wordsNumber, separateWords[5]) == 1);
    assert(occursWord(separateWords, wordsNumber, separateWords[6]) == 3);
    assert(occursWord(separateWords, wordsNumber, separateWords[9]) == 1);
    assert(occursWord(separateWords, wordsNumber, separateWords[10]) == 1);
    assert(occursWord(separateWords, wordsNumber, separateWords[11]) == 1);
    
    separateWords = freeArray(separateWords, &wordsNumber);

    text = freeArray(text, &linesNumber);
    printf("\"Final\" test completed.");
}

#undef main

int main() {
    isSomeCharTest();
    lineLengthTest();
    swapAndCompareStringsTest();
    toLowerTest();
    checkNULLTest();
    finalTest();

    return 0;
}
