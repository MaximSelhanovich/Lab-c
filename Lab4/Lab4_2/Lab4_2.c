#include <stdlib.h>
#include <stdio.h>
#include "Lab4_2.h"

int main() {

    long int maxPosition = 0;

    FILE *mainFile = fopen("Lab4_2.txt", "r");

    fseek(mainFile, 0, SEEK_END);
    maxPosition = ftell(mainFile);

    if (!mainFile) {
        printf("Error in opening file!\n");
        return -1;
    }

evenPalindrome(mainFile, maxPosition);

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

int isLetter(const char character) {
    if ((character >= 'A' && character <= 'Z')  ||
        (character >= 'a' && character <= 'z')) return 1;

        return 0;
}

void evenPalindrome(FILE *fileTORead, long int maxPosition) {
    long int leftMove = 0, rightMove = 0, currentPosition = 0, leftToWrite = 0, rightToWrite = 0;
    char leftChar, rightChar;
    int printFlag = 1;

    currentPosition = 1;
    leftMove = -currentPosition;
    rightMove = currentPosition - 1;
    leftToWrite = 0;
    rightToWrite = 2;

    while (currentPosition != maxPosition - 1) {
        while (currentPosition + rightMove <= maxPosition) {

            fseek(fileTORead, currentPosition, SEEK_SET);

            fseek(fileTORead, leftMove, SEEK_CUR);
            leftChar = fgetc(fileTORead);
            leftToWrite = currentPosition + leftMove;

            while(isLetter(leftChar) != 1) {
                --leftMove;
                leftChar = fgetc(fileTORead);
            }

            --leftMove;

            fseek(fileTORead, currentPosition, SEEK_SET);

            fseek(fileTORead, rightMove, SEEK_CUR);
            rightChar = fgetc(fileTORead);
            rightToWrite = currentPosition + rightMove;

            while(isLetter(rightChar) != 1) {
                ++rightMove;
                rightChar = fgetc(fileTORead);
            }

            ++rightMove;

            if (charToLower(leftChar) != charToLower(rightChar)) {
                ++currentPosition;
                printFlag = 0;
                break;
            }
        }

        if (printFlag) {
            printf("\n");
            fseek(fileTORead, leftToWrite, SEEK_SET);
            while (ftell(fileTORead) < rightToWrite) printf("%c", fgetc(fileTORead));
            ++currentPosition;
        }

        printFlag = 1;
        leftMove = -1;
        rightMove = 0;
    }

}

char charToLower(char character) {
    /*There are 32 characters between uppercase 
    and lowercase letters in ASCII*/
    if (character >= 'A' && character <= 'Z') return character + 32;

    return character;
}

/*int ch;
while ((ch = fgetc(file)) != EOF) {
    if (ch == '.') {

    } else {

    }
}*/