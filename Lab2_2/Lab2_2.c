#include <stdio.h>
#include <math.h>
#include "Lab2_2.h"

int main() {

    double x, calculationsError;

    printf("\nEnter the angle (in degrees): ");
    x = getValidDouble();

    printf("\nEnter calculation precision (must be less than 1): ");
    calculationsError = getValidDouble();

    while(calculationsError >= 1) {
        printf("Wrong input. Precision must be less than 1: ");
        calculationsError = getValidDouble();
    }

    x = simplifyAngleDegrees(x);
    printf("Angle id degrees: %lf\n", x);
    x = degreesToRadians(x);
    printf("Angle in radians: %lf\n", x);

    printf("\nIterative");
    calcSineDecompositionIterative(x, calculationsError);

    printf("\nRecursive");
    calcSineDecompositionRecursion(x, 0, calculationsError);
    printf("\n True");
    return 0;
}

double getValidDouble() {
    
    double temp;
    char goodCheck;

    while(!scanf("%lf", &temp) ||
          !scanf("%c", &goodCheck) || goodCheck != '\n') {
        printf("Wrong input!\nPlease, try again: ");
        fflush(stdin);
    }

    return temp;
}

double degreesToRadians(double degrees) {return degrees * PI / 180;}

double simplifyAngleDegrees(double angle) {
    if(angle > 0) {while(angle >= 360) angle -= 360;}
    else {while(angle <= -360) angle += 360;}
    return angle;
}

int calcSineDecompositionIterative(double x, double calculationsError) {

    double sinX = sin(x), decompositionSumX = 0,
           intermediateTerm = 1, calculationAccuracy = 0;
    int sign = 1, powOfX = 1, factorialDegree = 1, number = 0;

    do {
        ++number;
        for(;factorialDegree <= powOfX; ++factorialDegree) {
            intermediateTerm *= x/factorialDegree;
        }

        decompositionSumX += sign * intermediateTerm;
        calculationAccuracy = fabs(decompositionSumX - sinX);
        printf("\nResult of sin(x) function:            %lf\n"
               "Result on %3d step of decomposition:  %lf\n"
               "Calculation accuracy:                 %lf\n\n",
                sinX, number, decompositionSumX, calculationAccuracy);
        sign *= -1;
        powOfX += 2;
    }
    while(calculationAccuracy > calculationsError);

    return number;
}

/*For the first call 0 shoul be passed as first and second parametr*/
int calcSineDecompositionRecursion(double x, double sumX, double calculationsError) {

    static int numberRecursion = 1;
    int powOfX = 2 * numberRecursion - 1, factorialDegree = 1, sign = 1;
    double intermediateTerm = 1, calculationAccuracy, sinX = sin(x);

    if(numberRecursion % 2 == 0) sign = -1;

    for(;factorialDegree <= powOfX; ++factorialDegree) {
        intermediateTerm *= x / factorialDegree;
    }

    sumX += sign * intermediateTerm;
    calculationAccuracy = fabs(sumX - sinX);

    printf("\nResult of sin(x) function:            %lf\n"
           "Result on %3d step of decomposition:  %lf\n"
           "Calculation accuracy:                 %lf\n\n",
            sinX, numberRecursion, sumX, calculationAccuracy);

    if(calculationAccuracy > calculationsError) {
        ++numberRecursion;
        return calcSineDecompositionRecursion(x, sumX, calculationsError);
    }
    else {
        return numberRecursion; 
    }
}