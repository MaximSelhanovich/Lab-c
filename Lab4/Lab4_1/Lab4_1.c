#include <stdio.h>
#include <stdlib.h>
#include "Lab4_1.h"

int main() {
    char **text = NULL;
    char **separateWords = NULL;
    unsigned int linesNumber = 5, wordsNumber;

    text = getTwoDimensionalArray(linesNumber);
    getText(&text, &linesNumber);

    if (!text) return -1;
    
    wordsNumber = linesNumber * 10;
    separateWords = getTwoDimensionalArray(wordsNumber);

    getSeparateWords(text, linesNumber, &separateWords, &wordsNumber);
    if (!separateWords) return -1;

    printf("\nSeparate words\n");
    printArray(separateWords, wordsNumber);

    textToLower(separateWords, wordsNumber);
    printf("\nTo lower version of words\n");
    printArray(separateWords, wordsNumber);


    sortAlphabetically(separateWords, wordsNumber);
    printf("\nSorted version of words\n");
    printArray(separateWords, wordsNumber);

    countAmountOfWords(separateWords, wordsNumber);
    separateWords = freeArray(separateWords, &wordsNumber);

    text = freeArray(text, &linesNumber);
    return 0;
}

/*Does not include '\\n' and '\\0' when counting*/
unsigned int lineLength(const char *line) {
    unsigned int counter = 0;

    if (!line) return 0;

    while (line[counter] != '\0' && line[counter] != '\n') ++counter;
    return counter;
}

int isLetter(const char character) {

    if ((character >= 'A' && character <= 'Z')  ||
        (character >= 'a' && character <= 'z')) return 1;

        return 0;
}

int isDigit(const char character) {

    if (character >= '0' && character <= '9') return 1;

    return 0;
}

void swapStrings(char **firstLine, char **secondLine) {
    char *temp = *firstLine;
    *firstLine = *secondLine;
    *secondLine = temp;
}

int compareStrings(const char *firstLine, const char *secondLine) {

    while (*firstLine && *firstLine == *secondLine) {
        ++firstLine; 
        ++secondLine;
    }
    return (int) (*firstLine - *secondLine);
}

char charToLower(char character) {
    /*There are 32 characters between uppercase 
    and lowercase letters in ASCII*/
    if (character >= 'A' && character <= 'Z') return character + 32;

    return character;
}

void stringToLower(char *line) {
    unsigned int i = 0;

    if (!line) return;

    while (line[i] != '\0' && line[i] != '\n') {
        line[i] = charToLower(line[i]);
        ++i;
    }
}

void textToLower(char **text, unsigned int numberOfLines) {
    unsigned int i = 0;

    for (i = 0; i < numberOfLines; ++i) stringToLower(text[i]);
}

int checkNULL(void *ptr) {
    if (!ptr) {

        printf("\nMemory (re)allocation error!\n");
        return 1;
    }
    return 0;
}

char **getTwoDimensionalArray(unsigned int linesNumber) {
    char **text = NULL;
    unsigned int i = 0, j = 0;

    if (linesNumber <= 0) return NULL;

    text = (char **)malloc(linesNumber * sizeof(char *));
    if (checkNULL(text)) return NULL;

    for (i = 0; i < linesNumber; ++i) {

        text[i] = (char *)malloc(255 * sizeof(char));

        if (checkNULL(text[i])) {

            for (j = 0; j < i; ++j) free(text[j]);

            free(text);
            return NULL;
        }
    }
    return text;
}

char **freeArray(char **text, unsigned int *linesNumber) {
    unsigned int i = 0;

    if (!text) return NULL;

    for (i = 0; i < *linesNumber; ++i) {

        if (!text[i]) continue;
        free(text[i]);
    }

    free(text);
    *linesNumber = 0;
    return NULL;
}

char **expendText(char **text, unsigned int *linesNumber) {
    char **tempText = NULL;
    unsigned int i = 0, j = 0;

    if (!text) return NULL;

    tempText = (char **)realloc(text,
                                (*linesNumber + 3) * sizeof(char *));

    if (checkNULL(tempText)) {

        freeArray(text, linesNumber);
        return NULL;
    }

    for (i = *linesNumber; i < *linesNumber + 3; ++i) {

        tempText[i] = (char *)malloc(255 * sizeof(char));

        if (checkNULL(tempText[i])) {

            for (j = 0; j < i; ++j) free(tempText[j]);

            free(tempText);
            return NULL;
        }
    }
    *linesNumber += 3;
    return tempText;
}

char *resizeLine(char *line) {
    char *tempLine = NULL;
    unsigned int length = lineLength(line);

    tempLine = (char *)realloc(line, (length + 1) * sizeof(char));

    /*on "length" position '\n' is located*/
    line[length] = '\0';

    if (!tempLine) return line;

    return tempLine;
}

char **resizeText(char **text, unsigned int currentLines,
                               unsigned int *totalLines) {
    char **tempText = NULL;
    unsigned int i = 0;

    if (!text) return NULL;

    for (i = currentLines; i < *totalLines; ++i) free(text[i]);

    tempText = (char **)realloc(text, currentLines * sizeof(char *));

    if (!tempText) return text;

    for (i = 0; i < currentLines; ++i) tempText[i] = resizeLine(tempText[i]);

    *totalLines = currentLines;
    return tempText;
}

void getText(char ***text, unsigned int *linesNumber) {
    int i = -1;

    if (!*text) return;

    printf("Enter the text(double \"Enter\" to finish):\n");

    do {
        ++i;

        if (i >= *linesNumber) {
            *text = expendText(*text, linesNumber);

            if (checkNULL(text)) return;
        }
        fgets((*text)[i], 254, stdin);
    } 
    while ((*text)[i][0] != '\n');

    if (!i) *text = freeArray(*text, linesNumber);
    else *text = resizeText(*text, i, linesNumber);
}

void getSeparateWords (char **textToRead, unsigned int linesOfText,
                       char ***arrayToWrite, unsigned int *linesOfArray) {
    unsigned int lineToRead = 0, charToRead = 0;
    unsigned int lineToWrite = 0, charToWrite = 0;

    if (!textToRead || linesOfText <= 0 ||
        !*arrayToWrite || *linesOfArray <= 0) return;

    for (lineToRead = 0; lineToRead < linesOfText; ++lineToRead) {

        while (textToRead[lineToRead][charToRead] != '\0' &&
               textToRead[lineToRead][charToRead] != '\n') {

                   /*All characters except digits and letters are considered as "spaces"*/
            while (!isLetter(textToRead[lineToRead][charToRead]) &&
                   !isDigit(textToRead[lineToRead][charToRead])  &&
                    textToRead[lineToRead][charToRead] != '\0'   &&
                    textToRead[lineToRead][charToRead] != '\n')
                ++charToRead;

            while (isLetter(textToRead[lineToRead][charToRead]) ||
                   isDigit(textToRead[lineToRead][charToRead])) {

                    (*arrayToWrite)[lineToWrite][charToWrite] =
                    textToRead[lineToRead][charToRead];

                    ++charToRead;
                    ++charToWrite;
                }

            (*arrayToWrite)[lineToWrite][charToWrite] = '\0';
            if (charToWrite != 0) ++lineToWrite;

            if (lineToWrite >= *linesOfArray - 1) {

                *arrayToWrite = expendText(*arrayToWrite, linesOfArray);

                if (checkNULL(*arrayToWrite)) return;
            }
            charToWrite = 0;
        }
        charToRead = 0;
    }

    if (!lineToWrite) {
        *arrayToWrite = freeArray(*arrayToWrite, linesOfArray);
        return;
    }

    *arrayToWrite = resizeText(*arrayToWrite, lineToWrite, linesOfArray);
}

void sortAlphabetically(char **words, unsigned int numberOfWords) {
    unsigned int i = 0, j = 0;

    if (!words) return;

    for (i = 0; i < numberOfWords - 1; ++i)
        for (j = 0; j < numberOfWords - i - 1; ++j)
            if (compareStrings(words[j], words[j + 1]) > 0)
                swapStrings(&words[j], &words[j + 1]);
}

int occursWord(char **words, unsigned int numberOfWords, char *wordToLookFor) {
    unsigned int i = 0, counter = 0;


     if (!words || numberOfWords <= 0 || !wordToLookFor) return 0;

     for (i = 0; i < numberOfWords; ++i)
         if (compareStrings(words[i], wordToLookFor) == 0) ++counter;

     return counter;
}

void countAmountOfWords(char **words, unsigned int numberOfWords) {
    unsigned int i = 0, temp = 1;

    if (!words || numberOfWords <= 0) return;

    printf("\nWords:\n");   
    while (i < numberOfWords) {

        temp = occursWord(words, numberOfWords, words[i]);

        printf("\n%s - %u", words[i], temp);

        i += temp;
    }
}

void printArray(char **array, unsigned int size) {
    unsigned int i = 0;

    for (i = 0; i < size; ++i) printf("\n%s", array[i]);
}
