#include "Lab2_2.h"

#include <stdio.h>
#include <assert.h>
#include <float.h>

void testDegreesToRadians() {

    assert(degreesToRadians(20) - 0.349066 < 0.000001);
    printf("\nDegrees to radians test completed");
}

void testSimplifyAngleDegrees() {

    assert(simplifyAngleDegrees(390) - 30 < DBL_EPSILON);
    assert(simplifyAngleDegrees(-390) + 30 < DBL_EPSILON);
    assert(simplifyAngleDegrees(30) - 30 < DBL_EPSILON);
    printf("\nSimplify angle in degrees tests completed");
}

void testCalcSineDecompositionIterative() {

    assert(calcSineDecompositionIterative(0.349065, 0.01) == 1);
    printf("\nSine decomposition iterative tests completed");
}

void testCalcSineDecompositionRecursion() {

    assert(calcSineDecompositionRecursion(0.349065, 0.0, 0.01) == 1);
    printf("\nSine decomposition recursion test completed");
}

#undef main

int main() {

    testDegreesToRadians();
    testSimplifyAngleDegrees();
    testCalcSineDecompositionIterative();
    testCalcSineDecompositionRecursion();
    printf("\n\nAll tests completed");
    
    return 0;
}