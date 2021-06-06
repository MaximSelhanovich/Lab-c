#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include "DigitRank.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct BigInteger {
    unsigned int length;
    char sign;
    struct DigitRank *head;
    struct DigitRank *tail;
}BigInteger;

char myFabs(char value);

BigInteger* newBigInteger();

BigInteger *newBigIntegerValue(long int value);

void addFrontRank(BigInteger *bigInteger, DigitRank *rank);

void addFrontValue(BigInteger* bigInteger, char value);

void addEndRank(BigInteger* bigInteger, DigitRank *rank);

void addEndValue(BigInteger* bigInteger, char value);

void removeEnd(BigInteger* bigInteger);

void removeFront(BigInteger* bigInteger);

void clear(BigInteger* bigInteger);

void deleteBigInteger(BigInteger* bigInteger);

void printBigInteger(BigInteger* bigInteger);

char fabsCompareBigInteger(BigInteger *first, BigInteger *second);

BigInteger* copyBigInteger(BigInteger *copyFrom);

void twoPowerMultiplyBigInteger(BigInteger *toDouble, unsigned char power);

BigInteger* sumBigInteger(BigInteger *firstTerm,
                          BigInteger *secondTerm, char mod);

BigInteger* differenceBigInteger(BigInteger *decreasing,
                                 BigInteger *deduction, char mod);

BigInteger* multiplyBigInteger(BigInteger *firstFactor,
                               BigInteger *secondFactor, char mod);

BigInteger *divideBigInteger(BigInteger *dividend, BigInteger *divisor,
                             char modCopy, char ModDiv);

#endif
