#pragma once
#ifndef DIGITRANK_H
#define DIGITRANK_H

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct DigitRank {
    char value;

    struct DigitRank* next;
    struct DigitRank* prev;
}DigitRank;

char checkExistance(void *ptrToCheck, const char *textToPrint);

DigitRank* newDigitRankValue(char value);

DigitRank* newDigitRankRank(DigitRank *rank);

void printDigitRank(DigitRank *rank);

char sumRank(DigitRank *firstTerm, DigitRank *secondTerm);

char differenceRank(DigitRank *decreasing, DigitRank *deduction);

#endif