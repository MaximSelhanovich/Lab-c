#include "DigitRank.h"

char checkExistance(void *ptrToCheck, const char *textToPrint) {
    if (!ptrToCheck) {
        printf("\nWrong input. %s doesn't exist(is NULL).\n", textToPrint);
        return 0;
    }
    return 1;
}

DigitRank* newDigitRankValue(char value) {
    DigitRank* temp = NULL;

    if (value < -9 || value > 9) {
        printf("\nWrong input. (-9 <= digit rank <= 9)\n");
        return NULL;
    }

    temp = (DigitRank*)malloc(sizeof(DigitRank));

    if (!temp) {
        printf("\nError in creation digit rank.\n");
    }
    else {
        temp->value = value;
        temp->next = NULL;
        temp->prev = NULL;
    }

    return temp;
}

DigitRank* newDigitRankRank(DigitRank *rank) {
    DigitRank* temp = NULL;
    
    if (!rank) return NULL;
    temp = newDigitRankValue(rank->value);

    return temp;
}

void printDigitRank(DigitRank *rank) {
    printf("%d", (int)rank->value);
}

char sumRank(DigitRank *firstTerm, DigitRank *secondTerm) {
    if (!checkExistance(firstTerm, "First term(DigitRank)")) return CHAR_MIN;
    if (!checkExistance(secondTerm, "Second term(DigitRank")) return CHAR_MIN;

    return (firstTerm->value + secondTerm->value) % 10;
}

char differenceRank(DigitRank *decreasing, DigitRank *deduction) {
    if (!checkExistance(decreasing, "Decreasing(DigitRank")) return CHAR_MIN;
    if (!checkExistance(deduction, "Deduction(DigitRank")) return CHAR_MIN;

    return (decreasing->value - deduction->value) % 10;
}