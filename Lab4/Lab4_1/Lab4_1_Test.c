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
    fgets(firstLine, 6, stdin);
    /*Well yes*/
    fgets(secondLine, 9, stdin);
    
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

    firstLine = (char *)malloc(12 * sizeof(char));
    if (!firstLine) return;

    secondLine = (char *)malloc(12 * sizeof(char));
    if (!secondLine) {
        free(firstLine);
        return;
    }

    /*ToLoWeRtEsT*/
    fgets(firstLine, 12, stdin);
    /*tolowertest*/
    fgets(secondLine, 12, stdin);

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
#undef main

int main() {
    isSomeCharTest();
    lineLengthTest();
    swapAndCompareStringsTest();
    toLowerTest();
    checkNULLTest();

    return 0;
}