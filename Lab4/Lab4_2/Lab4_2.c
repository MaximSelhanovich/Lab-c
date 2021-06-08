#include <stdlib.h>
#include <stdio.h>
#include "Lab4_2.h"

void printfBetweenPositions(FILE* fileToRead, long int leftIndex, long int rightIndex) {
    char temp = 'a';

    printf("\n");
    fseek(fileToRead, leftIndex, SEEK_SET);

    while (ftell(fileToRead) <= rightIndex && temp != EOF) {
        temp = fgetc(fileToRead);
        //if (temp == '\n') temp = ' ';
        printf("%c", temp);
    }

    printf("\n");
}

char charToLower(char character) {
    /*There are 32 characters between uppercase
    and lowercase letters in ASCII*/
    if (character >= 'A' && character <= 'Z') return character + 32;

    return character;
}

int isLetter(const char character) {
    if ((character >= 'A' && character <= 'Z') ||
        (character >= 'a' && character <= 'z')) return 1;

    return 0;
}

int isDigit(const char character) {
    if (character >= '0' && character <= '9') return 1;

    return 0;
}

int isCharacter(const char character) {
    if (isLetter(character) || isDigit(character)) return 1;

    return 0;
}

void evenPalindroms(FILE* fileToRead) {
    long int temp = 1;
    long int currentPosition = 1;
    long int leftMove = 2;
    long int rightMove = temp;
    char outerLeftChar;
    char innerLeftChar;
    char innerRightChar;
    char outerRightChar;

    fseek(fileToRead, 0, SEEK_END);

    long int maxPosition = ftell(fileToRead);

    fseek(fileToRead, currentPosition, SEEK_SET);

    while (currentPosition < maxPosition) {
        while (currentPosition + rightMove <= maxPosition &&
               currentPosition - leftMove >= 0) {
            /*Taking two letf and two right letters*/

            if (currentPosition < leftMove) {
                printf("q");
                fseek(fileToRead, currentPosition - leftMove + 1, SEEK_SET);
                outerLeftChar = ' ';
            } else {
                fseek(fileToRead, currentPosition - leftMove, SEEK_SET);
                outerLeftChar = fgetc(fileToRead);
            }
            
            innerLeftChar = fgetc(fileToRead);

            int temp = 0;
            while ((!isCharacter(innerLeftChar)) && ftell(fileToRead) >= 3) {
                
                if (innerLeftChar == '\n') --temp;
                
                fseek(fileToRead, ftell(fileToRead) - 3, SEEK_CUR);
                outerLeftChar = fgetc(fileToRead);
                innerLeftChar = fgetc(fileToRead);
                ++leftMove;
            }

            fseek(fileToRead, currentPosition + rightMove, SEEK_SET);

            innerRightChar = fgetc(fileToRead);

            while (!isCharacter(innerRightChar) && ftell(fileToRead) < maxPosition) {
                /*printf("\n%d\n", (int)innerRightChar);*/
                ++rightMove;
                innerRightChar = fgetc(fileToRead);
            }

            if (ftell(fileToRead) == maxPosition) outerRightChar = ' ';
            else
                outerRightChar = fgetc(fileToRead);

            if (isCharacter(outerLeftChar) && isCharacter(outerRightChar) &&
                charToLower(outerLeftChar) != charToLower(outerRightChar)) {
                break;
            }

            if (!isCharacter(outerLeftChar) && !isCharacter(outerRightChar) &&
                isCharacter(innerLeftChar) &&
                charToLower(innerLeftChar) == charToLower(innerRightChar)) {

                printfBetweenPositions(fileToRead, currentPosition - leftMove + 1,
                currentPosition + rightMove + 1);
            }

            ++leftMove;
            ++rightMove;
        }

        ++currentPosition;
        leftMove = 2;
        rightMove = temp;
    }
}

int main() {

    long int maxPosition = 0;

    FILE* mainFile;

    mainFile = fopen("Lab4_2.txt", "r");

    if (!mainFile) {
        printf("Error in opening file!\n");
        return -1;
    }

    evenPalindroms(mainFile);

    fclose(mainFile);
    return 0;
}
