#include "BigInteger.h"

BigInteger* newBigInteger() {
    BigInteger* bigInteger = (BigInteger*)malloc(sizeof(BigInteger));

    if (!bigInteger) {
        printf("\nErrorr in list creation!\n");
    } else {
        bigInteger->sign = '+';
        bigInteger->length = 0;
        bigInteger->head = NULL;
        bigInteger->tail = NULL;
    }

    return bigInteger;
}

void addFrontRank(BigInteger* bigInteger, DigitRank* rank) {
    if (!checkExistance(bigInteger, "List")) return;
    if (!checkExistance(rank, "Digit rank")) return;
    if (rank->value < 0) {
        bigInteger->sign = '-';
        rank->value = -rank->value;
    } else {
        bigInteger->sign = '+';
    }

    if (!bigInteger->tail) {
        bigInteger->tail = rank;
    } else {
        if (bigInteger->head->value < 0) {
            printf("\nSign of previous head was changed to '+'."
                "Only first digit in BigInteger can be negative.\n");
            return;
        }

        bigInteger->head->prev = rank;
        rank->next = bigInteger->head;
    }

    ++bigInteger->length;
    bigInteger->head = rank;
}

void addFrontValue(BigInteger* bigInteger, char value) {
    DigitRank* temp = NULL;

    if (!checkExistance(bigInteger, "List")) return;

    temp = newDigitRankValue(value);

    if (!temp) {
        printf("\nError in additing node. It wasn't add.\n");
        return;
    }

    addFrontRank(bigInteger, temp);
}

BigInteger* newBigIntegerValue(long int value) {
    BigInteger* newBigInt = newBigInteger();

    while (value) {
        addFrontValue(newBigInt, value % 10);
        value /= 10;
    }

    if (value < 0) {
        newBigInt->sign = '-';
        newBigInt->head->value = -newBigInt->head->value;
    }

    return newBigInt;
}

void addEndRank(BigInteger* bigInteger, DigitRank* rank) {
    if (!checkExistance(bigInteger, "List")) return;
    if (!checkExistance(rank, "Digit rank")) return;

    if (!bigInteger->head) {
        if (rank->value < 0) {
            rank->value = -rank->value;
            bigInteger->sign = '-';
        }
        bigInteger->head = rank;
    } else {
        if (rank->value < 0) {
            printf("\nWrong input."
                "Only first digit in BigInteger can be negative.\n");
            return;
        }
        rank->prev = bigInteger->tail;
        bigInteger->tail->next = rank;
    }

    ++bigInteger->length;
    bigInteger->tail = rank;
}

void addEndValue(BigInteger* bigInteger, char value) {
    DigitRank* temp = NULL;

    if (!checkExistance(bigInteger, "List")) return;

    temp = newDigitRankValue(value);

    if (!temp) {
        printf("\nError in additing node. It wasn't add.\n");
        return;
    }
    addEndRank(bigInteger, temp);
}

void removeEnd(BigInteger* bigInteger) {
    DigitRank* oldTail = NULL;

    if (!bigInteger || !bigInteger->tail) {
        printf("\nErrororbrfgb removeend\n");
        return;
    }

    oldTail = bigInteger->tail;

    bigInteger->tail = bigInteger->tail->prev;

    if (!bigInteger->tail) bigInteger->head = NULL;
    else
        bigInteger->tail->next = oldTail->next;

    --bigInteger->length;
    free(oldTail);
}

void removeFront(BigInteger* bigInteger) {
    DigitRank* oldHead = NULL;

    if (!bigInteger || !bigInteger->head) return;
    if (bigInteger->sign == '-') bigInteger->sign = '+';
    oldHead = bigInteger->head;

    bigInteger->head = bigInteger->head->next;

    if (!bigInteger->head) bigInteger->tail = NULL;
    else
        bigInteger->head->prev = oldHead->prev;

    --bigInteger->length;
    free(oldHead);
}

void deleteBigInteger(BigInteger* bigInteger) {
    DigitRank* temp = NULL;

    if (!bigInteger) return;
    temp = bigInteger->head;

    while (bigInteger->head) {
        temp = bigInteger->head->next;
        free(bigInteger->head);
        bigInteger->head = temp;
    }

    free(bigInteger);
}

void printBigInteger(BigInteger* bigInteger) {
    DigitRank* temp = NULL;

    if (!bigInteger || !bigInteger->tail) return;

    temp = bigInteger->head;
    printf("\nBigInteger: %c", bigInteger->sign);
    while (temp) {
        printDigitRank(temp);
        temp = temp->next;
    }
}

char fabsCompareBigInteger(BigInteger* first, BigInteger* second) {
    DigitRank* tempFirstRank = NULL;
    DigitRank* tempSecondRank = NULL;

    if (!checkExistance(first, "First BigInteger") ||
        !checkExistance(first->tail, "First BigInteger"))
        return CHAR_MIN;

    if (!checkExistance(second, "Second BigInteger") ||
        !checkExistance(second->tail, "Second BigInteger"))
        return CHAR_MIN;

    if (first->length < second->length) return -1;
    if (first->length > second->length) return 1;

    tempFirstRank = first->head;
    tempSecondRank = second->head;

    while (tempFirstRank) {
        if (tempFirstRank->value < tempSecondRank->value) return -1;

        if (tempFirstRank->value > tempSecondRank->value) return 1;
        tempFirstRank = tempFirstRank->next;
        tempSecondRank = tempSecondRank->next;
    }

    return 0;
}

BigInteger* copyBigInteger(BigInteger* copyFrom) {
    DigitRank* tempDigitRank = NULL;
    BigInteger* tempBigInteger = NULL;

    if (!copyFrom || !copyFrom->head) return NULL;

    tempBigInteger = newBigInteger();

    tempDigitRank = copyFrom->tail;

    while (tempDigitRank) {
        addFrontValue(tempBigInteger, tempDigitRank->value);
        tempDigitRank = tempDigitRank->prev;
    }

    tempBigInteger->sign = copyFrom->sign;

    return tempBigInteger;
}

void twoPowerMultiplyBigInteger(BigInteger* toDouble, unsigned char power) {
    DigitRank* tempRank = NULL;
    char tempValue = 0;
    if (!toDouble || !toDouble->tail) return;

    tempRank = toDouble->tail;

    if (power > 3) {
        printf("\nUnfortunately only power 3 is available.\n");
        return;
    }

    while (tempRank) {
        tempValue += (tempRank->value << power);
        tempRank->value = tempValue % 10;
        tempValue /= 10;
        tempRank = tempRank->prev;
    }

    while (tempValue) {
        addFrontValue(toDouble, tempValue % 10);
        tempValue /= 10;
    }
}

/*If (mod == 0) then create new BigInteger,
  if (mod == 1) modify greater BigInteger*/
BigInteger* sumBigInteger(BigInteger* firstTerm,
    BigInteger* secondTerm, char mod) {
    char tempRank = 0;
    BigInteger* sum = firstTerm;
    DigitRank* tempFirstTermRank = NULL;
    DigitRank* tempSecondTermRank = NULL;

    if (!checkExistance(firstTerm, "First term(BigInteger)") ||
        !checkExistance(firstTerm->tail, "First term(BigInteger)"))
        return NULL;

    if (!checkExistance(secondTerm, "Second term(BigInteger)") ||
        !checkExistance(secondTerm->tail, "Second term(BigInteger)"))
        return NULL;

    tempFirstTermRank = firstTerm->tail;
    tempSecondTermRank = secondTerm->tail;

    if (!mod) {
        sum = newBigInteger();
        sum->sign = firstTerm->sign;
    }

    if (firstTerm->sign == secondTerm->sign) {
        while (tempFirstTermRank || tempSecondTermRank) {
            if (tempFirstTermRank) {
                tempRank += tempFirstTermRank->value;
                tempFirstTermRank = tempFirstTermRank->prev;
            }

            if (tempSecondTermRank) {
                tempRank += tempSecondTermRank->value;
                tempSecondTermRank = tempSecondTermRank->prev;
            }

            if (mod) {
                if (!tempFirstTermRank) addFrontValue(firstTerm, tempRank % 10);
                else
                    tempFirstTermRank->value = tempRank % 10;
            } else {
                addFrontValue(sum, tempRank % 10);
            }

            tempRank /= 10;
        }

        if (tempRank) addFrontValue(sum, tempRank % 10);
        tempRank = 0;
    } else {
        tempRank = firstTerm->sign;
        firstTerm->sign = secondTerm->sign;

        sum = differenceBigInteger(firstTerm, secondTerm, mod);

        firstTerm->sign = tempRank;
    }

    return sum;
}

/*If (mod == 0) then create new BigInteger,
  if (mod == 1) modify greater BigInteger*/
BigInteger* differenceBigInteger(BigInteger* decreasing,
    BigInteger* deduction, char mod) {
    BigInteger* difference = decreasing;
    char tempRank = 0;
    DigitRank* tempDecreasingRank = NULL;
    DigitRank* tempDeductionRank = NULL;

    if (!checkExistance(decreasing, "Decreasing(BigInteger)") ||
        !checkExistance(decreasing->head, "Decreasing(BigInteger)"))
        return NULL;

    if (!checkExistance(deduction, "Deduction(BigInteger)") ||
        !checkExistance(deduction->head, "Deduction(BigInteger)"))

        return NULL;
    tempDecreasingRank = decreasing->tail;
    tempDeductionRank = deduction->tail;

    tempRank = fabsCompareBigInteger(decreasing, deduction);

    if (!tempRank) {
        if (decreasing->sign != deduction->sign) {
            difference = newBigIntegerValue(0);
        } else {
            difference = copyBigInteger(deduction);
            twoPowerMultiplyBigInteger(difference, 1);
        }

        if (mod) deleteBigInteger(decreasing);
        return difference;
    } else if (tempRank == -1) {
        difference = copyBigInteger(deduction);
        tempDeductionRank = decreasing->tail;

        if (decreasing->sign != deduction->sign) {
            difference->sign = decreasing->sign;
            difference = sumBigInteger(difference, decreasing, 1);
        }

    } else {
        difference = copyBigInteger(decreasing);
        tempDeductionRank = deduction->tail;
        if (decreasing->sign != deduction->sign) {
            difference->sign = decreasing->sign;
            difference = sumBigInteger(difference, deduction, 1);
        }
    }

    tempRank = 0;
    tempDecreasingRank = difference->tail;
    if (decreasing->sign == deduction->sign) {
        while (tempDecreasingRank || tempDeductionRank) {
            if (tempDecreasingRank) {
                tempRank += tempDecreasingRank->value;
            }

            if (tempDeductionRank) {
                tempRank -= tempDeductionRank->value;
            }

            if (tempRank < 0) {
                tempDecreasingRank->value = tempRank + 10;
                tempRank = -1;
            } else if (tempDecreasingRank) {
                tempDecreasingRank->value = tempRank;
                tempRank = 0;
            }

            tempDecreasingRank = tempDecreasingRank->prev;

            if (tempDeductionRank) {
                tempDeductionRank = tempDeductionRank->prev;
            }
        }

        if (!difference->head->value) {
            removeFront(difference);
        }
    }

    if (mod) deleteBigInteger(decreasing);
    return difference;
}

/*If (mod == 0) then create new BigInteger,
  if (mod == 1) modify first BigInteger*/
BigInteger* multiplyBigInteger(BigInteger* firstFactor,
    BigInteger* secondFactor, char mod) {
    char tempRank = 0;
    BigInteger* product = firstFactor;
    DigitRank* tempFirstFactorRank = NULL;
    DigitRank* tempSecondFactorRank = NULL;
    BigInteger* deleteLater = firstFactor;
    DigitRank* endOfFirstBigInt = NULL;
    DigitRank* currentElement = NULL;
    DigitRank* returnToPosition = NULL;
    char flag = 0;

    if (!checkExistance(firstFactor, "First factor(BigInteger)") ||
        !checkExistance(firstFactor->tail, "First factor(BigInteger)"))
        return NULL;

    if (!checkExistance(secondFactor, "Second factor(BigInteger)") ||
        !checkExistance(secondFactor->tail, "Second factor(BigInteger)"))
        return NULL;

    tempFirstFactorRank = firstFactor->tail;
    tempSecondFactorRank = secondFactor->tail;
    deleteLater = firstFactor;

    if (firstFactor->head->value == 0 || secondFactor->head->value == 0) {
        if (mod) deleteBigInteger(product);
        product = newBigIntegerValue(0);
        return product;
    }

    tempRank = fabsCompareBigInteger(firstFactor, secondFactor);

    if (tempRank == -1) {
        tempFirstFactorRank = secondFactor->tail;
        product = copyBigInteger(secondFactor);
        tempSecondFactorRank = firstFactor->tail;
    } else {
        product = copyBigInteger(firstFactor);
    }

    endOfFirstBigInt = tempFirstFactorRank;
    currentElement = product->tail;
    returnToPosition = product->tail;

    flag = 0;
    tempRank = 0;
    while (tempSecondFactorRank) {
        while (tempFirstFactorRank) {
            tempRank += tempSecondFactorRank->value *
                        tempFirstFactorRank->value;

            if (flag) tempRank += currentElement->value;

            currentElement->value = tempRank % 10;
            tempRank /= 10;

            if ((tempRank || tempFirstFactorRank->prev) &&
                !currentElement->prev) {
                addFrontValue(product, tempRank);
                tempRank = 0;
            }

            currentElement = currentElement->prev;
            tempFirstFactorRank = tempFirstFactorRank->prev;
        }

        flag = 1;
        returnToPosition = returnToPosition->prev;
        currentElement = returnToPosition;
        tempFirstFactorRank = endOfFirstBigInt;
        tempSecondFactorRank = tempSecondFactorRank->prev;
    }
    if (mod) deleteBigInteger(deleteLater);

    return product;
}

/*If (modCopyBlock == 0) then create new BigInteger,
  if (modCopyBlock == 1) modify first BigInteger
  If (ModDiv == 0) return (firstBigInteger % secondBigInteger)
  if (ModDiv == 1) return (firstBigInteger / secondBigInteger)*/
BigInteger* divideBigInteger(BigInteger* dividend, BigInteger* divisor,
    char modCopyBlock, char ModDiv) {

    char tempRank = 0;
    BigInteger* quotient = dividend;
    long int result = 0;
    char temp = 0;

    if (!checkExistance(dividend, "Dividend(BigInteger)") ||
        !checkExistance(dividend->tail, "Dividend(BigInteger)"))
        return NULL;

    if (!checkExistance(divisor, "Divisor(BigInteger)") ||
        !checkExistance(divisor->tail, "Divisor(BigInteger)"))
        return NULL;

    if (!divisor->head->value) {
        printf("\nERROR! Division by zero!\n");
        return NULL;
    }

    tempRank = fabsCompareBigInteger(dividend, divisor);

    if (!tempRank) {
        if (!ModDiv) result = 0;
        else
            result = 1;

        if (modCopyBlock) deleteBigInteger(quotient);
        quotient = newBigIntegerValue(result);
    } else if (tempRank == -1) {
        if (ModDiv) {
            result = 0;
            if (modCopyBlock) deleteBigInteger(quotient);
            quotient = newBigIntegerValue(result);
        } else {
            if (modCopyBlock) {
                quotient = dividend;
            } else {
                quotient = copyBigInteger(dividend);
            }
        }
    } else {
        quotient = copyBigInteger(dividend);

        while ((temp = fabsCompareBigInteger(quotient, divisor)) == 1) {
            /*result == (firstBigInteger / secondBigInteger)*/
            ++result;
            /*quotient == (firstBigInteger % secondBigInteger)*/
            quotient = differenceBigInteger(quotient, divisor, 1);
        }

        if (!temp) {
            ++result;
            deleteBigInteger(quotient);
            quotient = newBigIntegerValue(0);
        }

        if (!quotient->head || !quotient->head->value) {
            printBigInteger(quotient);
            removeFront(quotient);
            printBigInteger(quotient);
        }

        if (modCopyBlock) deleteBigInteger(dividend);

        if (ModDiv) {
            deleteBigInteger(quotient);
            quotient = newBigIntegerValue(result);
        }
    }
    return quotient;
}
