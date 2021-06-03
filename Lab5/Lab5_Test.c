#include "Lab5.h"
#include "BigInteger.h"
#include <assert.h>

void testcalculateMersenne() {
    BigInteger *mersenne = calculateMersenne(7);/*result 127*/
    BigInteger *test = newBigInteger();
    DigitRank *forMersenne = NULL;
    DigitRank *forTest = NULL;

    addFrontValue(test, 7);
    addFrontValue(test, 2);
    addFrontValue(test, 1);
    
    forMersenne = mersenne->head;
    forTest = test->head;
    assert(forMersenne->value == forTest->value);
    
    forMersenne = forMersenne->next;
    forTest = forTest->next;
    assert(forMersenne->value == forTest->value);
    
    forMersenne = forMersenne->next;
    forTest = forTest->next;
    assert(forMersenne->value == forTest->value);
    
    printf("\nTest calculateMersenne is complited.\n");
    delete(mersenne);
    delete(test);
}

void testLucasLehmerRrimalityTest() {
    int test = LucasLehmerRrimalityTest(-5);
    assert(test == INT_MIN);

    test = LucasLehmerRrimalityTest(8);
    assert(test == INT_MIN);

    test = LucasLehmerRrimalityTest(9);
    assert(test);

    test = LucasLehmerRrimalityTest(17);
    assert(test);
    
    printf("\nTest LucasLehmerRrimalityTest is complited.\n");
}

#undef main

int main() {
    testcalculateMersenne();
    testLucasLehmerRrimalityTest();

    return 0;
}
