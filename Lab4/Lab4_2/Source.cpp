#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
//#include "Lab4_2.h"

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
            //w hile
            int temp = 0;
            while ((!isCharacter(innerLeftChar)) && ftell(fileToRead) >= 3) {

                /*printf("%d \t %d \t %d\n", (int)innerLeftChar, (int)outerLeftChar, ftell(fileToRead));*/
                
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

/*void evenPalindroms(FILE* fileTORead, long int maxPosition) {
    long int leftMove = 0, rightMove = 0, currentPosition = 0, leftToWrite = 0, rightToWrite = 0;
    char leftChar, rightChar;
    int printFlag = 1;

    currentPosition = 1;
    leftMove = -currentPosition;
    rightMove = currentPosition - 1;
    leftToWrite = 0;
    rightToWrite = 2;

    while (currentPosition != maxPosition) {
        while (currentPosition + rightMove <= maxPosition && currentPosition + leftMove >= 0) {

            fseek(fileTORead, currentPosition, SEEK_SET);

            fseek(fileTORead, leftMove, SEEK_CUR);
            leftChar = fgetc(fileTORead);
            leftToWrite = currentPosition + leftMove;

            --leftMove;

            fseek(fileTORead, currentPosition, SEEK_SET);

            fseek(fileTORead, rightMove, SEEK_CUR);
            rightChar = fgetc(fileTORead);
            rightToWrite = currentPosition + rightMove;

            ++rightMove;

            if (isLetter(leftChar) != 1 && isLetter(rightChar) != 1 && rightChar != EOF) {
                printfBetweenPositions(fileTORead, leftToWrite, rightToWrite);
            }

            while (isLetter(leftChar) != 1 && ftell(fileTORead)) {
                --leftMove;
                leftChar = fgetc(fileTORead);
            }

            //--leftMove;

            /*fseek(fileTORead, currentPosition, SEEK_SET);

            fseek(fileTORead, rightMove, SEEK_CUR);
            rightChar = fgetc(fileTORead);
            rightToWrite = currentPosition + rightMove;

            while (isLetter(rightChar) != 1 && rightChar != EOF) {
                ++rightMove;
                rightChar = fgetc(fileTORead);
            }

            //++rightMove;

            if (charToLower(leftChar) != charToLower(rightChar) && rightChar != EOF) {
                ++currentPosition;
                printFlag = 0;
                break;
            }
        }

        if (printFlag) {
            printfBetweenPositions(fileTORead, leftToWrite, rightToWrite);
            ++currentPosition;
        }

        printFlag = 1;
        leftMove = -1;
        rightMove = 0;
    }
}*/

int main() {

    long int maxPosition = 0;

    FILE* mainFile;

    mainFile = fopen("Lab4_2.txt", "r");

    /*fseek(mainFile, 0, SEEK_END);
    maxPosition = ftell(mainFile);*/

    if (!mainFile) {
        printf("Error in opening file!\n");
        return -1;
    }

    evenPalindroms(mainFile);

    /*fseek(fp,3,SEEK_CUR);
    while(fp!=EOF)
    {
        ch = fgetc (fp); // moves offset by 1
        fseek(fp,2,SEEK_CUR); // moves offset by another 2
        printf("%c",ch);
    }
        long int leftHand = 0, rightHand = 0;
        fseek(mainFile, 0, SEEK_END);
        printf("End of file -- %d", ftell(mainFile));*/

    fclose(mainFile);
    return 0;
}

/*int ch;
while ((ch = fgetc(file)) != EOF) {
    if (ch == '.') {

    } else {

    }
}*/

