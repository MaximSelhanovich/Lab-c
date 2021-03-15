#include "Lab2_2.h"

#include <stdio.h>
#include <assert.h>
#include <float.h>

void testDegreesToRadians() {

    assert(degreesToRadians(180) - 3.1415926535 < DBL_EPSILON);
    printf("Degrees to radians test complet");
}

void testSimplifyAngleDegrees() {

    assert(simplifyAngleDegrees(390) - 30 < DBL_EPSILON);
    assert(simplifyAngleDegrees(-390) + 30 < DBL_EPSILON);
    assert(simplifyAngleDegrees(30) - 30 < DBL_EPSILON);
    printf("Simplify angle in degrees test complet");
}

void testCalcSineDecompositionIterative() {

    assert(calcSineDecompositionIterative(0.349065, 0.01) == 1);
    printf("Sine decomposition iterative test complet");
}

void testCalcSineDecompositionRecursion() {

    assert(calcSineDecompositionRecursion(0.349065, 0.0, 0.01) == 1);
    printf("Sine decomposition iterative test complet");
}

#undef main

int main() {

    testDegreesToRadians();
    testSimplifyAngleDegrees();
    testCalcSineDecompositionIterative();
    testCalcSineDecompositionRecursion();
    printf("All testc are completed");
    
    return 0;
}
