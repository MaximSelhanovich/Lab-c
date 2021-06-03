#include "BigInteger.h"

char myFabs(char value) {
    if (value < 0) return -value;
    return value;
}

BigInteger* newBigInteger() {
    BigInteger *bigInteger = (BigInteger*)malloc(sizeof(BigInteger));

    if (!bigInteger) {
        printf("\nErrorr in list creation!\n");
    }
    else {
        bigInteger->sign = '+';
        bigInteger->length = 0;
        bigInteger->head = NULL;
        bigInteger->tail = NULL;
    }

    return bigInteger;
}

BigInteger *newBigIntegerValue(long int value) {
    BigInteger *newBigInt = newBigInteger();

    while (value) {
        addFrontValue(newBigInt, value % 10);
        value /= 10;
    }
    if (newBigInt->head->value < 0) {
        newBigInt->sign = '-';
        newBigInt->head->value = -newBigInt->head->value;
    }

    return newBigInt;
}

void addFrontRank(BigInteger *bigInteger, DigitRank *rank) {
    if (!checkExistance(bigInteger, "List")) return;
    if (!checkExistance(rank, "Digit rank")) return;
    if (rank->value < 0) {
        bigInteger->sign = '-';
        rank->value = -rank->value;
    }
    else {
        bigInteger->sign = '+';
    }

    if (!bigInteger->tail) {
        bigInteger->tail = rank;
    }
    else {
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
    DigitRank *temp = NULL;

    if (!checkExistance(bigInteger, "List")) return;

    temp = newDigitRankValue(value);

    if (!temp) {
        printf("\nError in additing node. It wasn't add.\n");    
        return;
    }

    addFrontRank(bigInteger, temp);
}

void addEndRank(BigInteger* bigInteger, DigitRank *rank) {
    if (!checkExistance(bigInteger, "List")) return;
    if (!checkExistance(rank, "Digit rank")) return;

    if (!bigInteger->head) {
        if (rank->value < 0) {
            rank->value = -rank->value;
            bigInteger->sign = '-';
        }
        bigInteger->head = rank;
    } 
    else {
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
    DigitRank *temp = NULL;

    if (!checkExistance(bigInteger, "List")) return;

    temp = newDigitRankValue(value);

    if (!temp) {
        printf("\nError in additing node. It wasn't add.\n");    
        return;
    }
    addEndRank(bigInteger, temp);
}

void removeEnd(BigInteger* bigInteger) {
    DigitRank *oldTail = NULL;

    if(!bigInteger || !bigInteger->tail) {
        printf("\nErrororbrfgb removeend\n");
        return;
    }

    oldTail = bigInteger->tail;

    bigInteger->tail = bigInteger->tail->prev;

    if (!bigInteger->tail) bigInteger->head = NULL;
    else bigInteger->tail->next = oldTail->next;

    --bigInteger->length;
    free(oldTail);
}

void removeFront(BigInteger* bigInteger) {
    DigitRank *oldHead = NULL;

    if(!bigInteger || !bigInteger->head) return;
    if (bigInteger->sign == '-') bigInteger->sign = '+';
    oldHead = bigInteger->head;

    bigInteger->head = bigInteger->head->next;

    if (!bigInteger->head) bigInteger->tail = NULL;
    else bigInteger->head->prev = oldHead->prev;

    --bigInteger->length;
    free(oldHead);
}

void clear(BigInteger* bigInteger) {
    DigitRank *temp = NULL;

    if (!bigInteger) return;

    temp = bigInteger->head;

    while (bigInteger->head) {
        temp = bigInteger->head->next;

        free(bigInteger->head);

        bigInteger->head = temp;
    }
    bigInteger->tail = NULL;

    bigInteger->length = 0;
    bigInteger->sign = '+';
}

void delete(BigInteger* bigInteger) {
    clear(bigInteger);

    free(bigInteger);
}

void printBigInteger(BigInteger* bigInteger) {
    DigitRank *temp = NULL;

    if (!bigInteger) return;

    temp = bigInteger->head;
    printf("\nBigInteger: %c", bigInteger->sign);
    while (temp) {
        printDigitRank(temp);
        temp = temp->next;
    }
}

char fabsCompareBigInteger(BigInteger *first, BigInteger *second) {
    DigitRank *tempFirstRank = NULL;
    DigitRank *tempSecondRank = NULL;

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

BigInteger* copyBigInteger(BigInteger *copyFrom) {
    DigitRank *tempDigitRank = NULL;
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

void twoPowerMultiplyBigInteger(BigInteger *toDouble, unsigned char power) {
    DigitRank *tempRank = toDouble->tail;
    char tempValue = 0;
    if (!toDouble || !toDouble->tail) return;

    if (power > 3) {
        printf("\nUnfortunately only power 3 is available.\n");
        return;
    }

    while(tempRank) {
        tempValue += tempRank->value << power;
        tempRank->value = tempValue % 10;
        tempValue /= 10;
        tempRank = tempRank->prev;
    }

    while (tempValue) {
        addFrontValue(toDouble, tempValue % 10);
        tempValue /= 10;
    }
}

BigInteger* sumBigInteger(BigInteger *firstTerm,
                          BigInteger *secondTerm, char mod) {
    char tempRank = 0;
    BigInteger *sum = firstTerm;
    DigitRank *tempFirstTermRank = NULL;
    DigitRank *tempSecondTermRank = NULL;

    if (!checkExistance(firstTerm, "First term(BigInteger)") ||
        !checkExistance(firstTerm->tail, "First term(BigInteger)"))
        return NULL;

    if (!checkExistance(secondTerm, "Second term(BigInteger)") ||
        !checkExistance(secondTerm->tail, "Second term(BigInteger)"))
        return NULL;
    
    tempFirstTermRank = firstTerm->tail;
    tempSecondTermRank = secondTerm->tail;

    tempRank = fabsCompareBigInteger(firstTerm, secondTerm)
    if (tempRank == -1){
        tempFirstTermRank = secondTerm->tail;
        tempSecondTermRank = firstTerm->tail;
    }
    
    if (!mod) { 
        sum = newBigInteger();
        sum->sign = firstTerm->sign; 
    }
    
    tempRank = 0;
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
                else tempFirstTermRank->value = tempRank % 10;
            }
            else addFrontValue(sum, tempRank % 10);
            
            tempRank /= 10;
        }

        if (tempRank) addFrontValue(sum, tempRank % 10);
        tempRank = 0;
    } else {
        while (tempFirstTermRank || tempSecondTermRank) {
            if (tempFirstTermRank) {
                tempRank += tempFirstTermRank->value -
                            tempSecondTermRank->value;

                tempSecondTermRank = tempSecondTermRank->prev;
            } else {
                tempRank += tempFirstTermRank->value;
            }
            
            if (tempFirstTermRank->prev && tempRank < 0) {
                if (mod) tempFirstTermRank->value = tempRank + 10;
                else addFrontValue(sum, tempRank + 10);
                tempRank = -1;
            } else {
                if (mod) tempFirstTermRank->value = tempRank;
                else
                    addFrontValue(sum, tempRank);
                tempRank = 0;
            }

            tempFirstTermRank = tempFirstTermRank->prev;
        }

        /*if (!sum->head->value) removeFront(sum);*/
    }

    return sum;
}

/*If (mod == 0) then create new BigInteger,
  if (mod == 1) modify greater BigInteger*/
BigInteger* differenceBigInteger(BigInteger *decreasing,
                                 BigInteger *deduction, char mod) {
    BigInteger* difference = NULL;
    
    if (!checkExistance(decreasing, "Decreasing(BigInteger)") ||
        !checkExistance(decreasing->head, "Decreasing(BigInteger)"))
        return NULL;

    if (!checkExistance(deduction, "Deduction(BigInteger)") ||
        !checkExistance(deduction->head, "Deduction(BigInteger)"))
        return NULL;


    deduction->sign = '-';

    difference = sumBigInteger(decreasing, deduction, mod);

    deduction->sign = '+';

    return difference;
}

/*If (mod == 0) then create new BigInteger,
  if (mod == 1) modify greater BigInteger*/
BigInteger* multiplyBigInteger(BigInteger *firstFactor,
                               BigInteger *secondFactor, char mod) {
    char tempRank = 0;
    BigInteger* product = firstFactor;
    DigitRank *tempFirstFactorRank = firstFactor->tail;
    DigitRank *tempSecondFactorRank = secondFactor->tail;
    BigInteger *deleteLater = NULL;
    DigitRank *endOfFirstBigInt = NULL;
    DigitRank *currentElement = NULL;
    DigitRank *returnToPosition = NULL;
    char flag = 0;
    if (!checkExistance(firstFactor, "First factor(BigInteger)") ||
        !checkExistance(firstFactor->tail, "First factor(BigInteger)"))
        return NULL;

    if (!checkExistance(secondFactor, "Second factor(BigInteger)") ||
        !checkExistance(secondFactor->tail, "Second factor(BigInteger)"))
        return NULL;

    if (firstFactor->head->value == 0 || secondFactor->head->value == 0) {
        if (mod) clear(product);
        else product = newBigInteger();
        addFrontValue(product, 0);
        return product;
    }    
 
    tempRank = fabsCompareBigInteger(firstFactor, secondFactor);
    
    if (tempRank == -1) {
        tempFirstFactorRank = secondFactor->tail;
        product = copyBigInteger(secondFactor);
        deleteLater = secondFactor;
        tempSecondFactorRank = firstFactor->tail;
    }
    else {
        product = copyBigInteger(firstFactor);
        deleteLater = firstFactor;
    }
    endOfFirstBigInt = tempFirstFactorRank;
    currentElement = product->tail;
    returnToPosition = product->tail;
    flag = 0;
    tempRank = 0;
    while (tempSecondFactorRank) {

        while (tempFirstFactorRank) {
            tempRank += tempSecondFactorRank->value * tempFirstFactorRank->value;

            if (flag) tempRank += currentElement->value;
   
            currentElement->value = tempRank % 10;
            tempRank /= 10;

            if ((tempRank || tempFirstFactorRank->prev) && !currentElement->prev) {
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
    if (mod) delete(deleteLater);


    return product;
}

/*If (modCopyBlock == 0) then create new BigInteger,
  if (modCopyBlock == 1) modify greater BigInteger
  If (ModDiv == 0) return (firstBigInteger % secondBigInteger)
  if (ModDiv == 1) return (firstBigInteger / secondBigInteger)*/
BigInteger *divideBigInteger(BigInteger *dividend, BigInteger *divisor,
                             char modCopyBlock, char ModDiv) {
                                 
    char tempRank = 0;
    BigInteger* quotient = dividend;
    DigitRank *tempFirstFactorRank = dividend->tail;
    DigitRank *tempSecondFactorRank = divisor->tail;
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
    
    if (!modCopyBlock) quotient = newBigInteger();
    tempRank = fabsCompareBigInteger(dividend, divisor);
    
    if (tempRank != 1 && ModDiv) {
        if (modCopyBlock) clear(quotient);

        if (tempRank) addFrontValue(quotient, 0);    
        else {
            if (tempFirstFactorRank->value != tempSecondFactorRank->value)
                addFrontValue(quotient, -1);
            else addFrontValue(quotient, 1);
        }

        return quotient;
    }

    if (!ModDiv && modCopyBlock) {
        if (tempRank == -1) return quotient;
        else if(!tempRank) {
            clear(quotient);
            addFrontValue(quotient, 0);
            printf("\n\n\nNot Here\n\n");
            return quotient;
        }
    }   

    quotient = copyBigInteger(dividend);

    while ((temp = fabsCompareBigInteger(quotient, divisor)) != -1) {
        /*result == (firstBigInteger / secondBigInteger)*/
        ++result;
        /*quotient == (firstBigInteger % secondBigInteger)*/
        quotient = differenceBigInteger(quotient, divisor, 1);
    }

    if (!temp) {
        ++result;
        clear(quotient);
        addFrontValue(quotient, 0);
    }

    if (modCopyBlock) delete(dividend);

    if (ModDiv) {
        delete(quotient);
        quotient = newBigIntegerValue(result);
    }

    return quotient;
}
