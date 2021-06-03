#include "Lab5.h"

int main() {
    int temp = LucasLehmerRrimalityTest(7);
    if(temp) printf("\nLooooh");
    else printf("\nNoooo");
    return 0;
}

BigInteger* calculateMersenne(int power) {
    BigInteger *number = NULL;
    BigInteger *one = NULL;
    int bigLoop = power / 3;
    int smallLoop = power % 3;
    int i = 0;

    if (power <= 0) {
        printf("\nPower must be positive.\n");
        return NULL;
    }

    one = newBigIntegerValue(1);
    number = newBigIntegerValue(1);

    for (i = 0; i < bigLoop; ++i) {
        twoPowerMultiplyBigInteger(number, 3);
    }
    
    for (i = 0; i < smallLoop; ++i) {
        twoPowerMultiplyBigInteger(number, 1);
    }
    
    differenceBigInteger(number, one, 1);

    delete(one);
    printBigInteger(number);
    return number;
}

int LucasLehmerRrimalityTest(int power) {
    BigInteger *remainder = NULL;
    BigInteger *tempRemainder = NULL;
    BigInteger *two = NULL;
    BigInteger *Mersenne = NULL;
    int i = 0;

    if (!(power % 2)) {
        printf("\nPower must be at least odd.\n");
        return INT_MIN;
    }

    remainder = newBigIntegerValue(4);
    two = newBigIntegerValue(2);
    Mersenne = calculateMersenne(power);

    if(!Mersenne) {
        delete(remainder);
        delete(two);
    } return INT_MIN;

    for (i = 0; i < power - 2; ++i) {
        tempRemainder = remainder;   
        remainder = multiplyBigInteger(remainder, remainder, 0);

        delete(tempRemainder);
        
        remainder = differenceBigInteger(remainder, two, 1);

        remainder = divideBigInteger(remainder, Mersenne, 1, 0);
    }

    i = remainder->head->value;

    delete(remainder);
    delete(two);
    delete(Mersenne);

    if (!i) return 1;
    else return 0;
}
