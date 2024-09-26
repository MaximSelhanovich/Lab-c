#ifndef LAB2_2_H
#define LAB2_2_H

#define PI 3.1415926535

int calcSineDecompositionIterative(double x, double calculationsError);
int calcSineDecompositionRecursion(double x, double sumX, double calculationsError);

double getValidDouble();

double degreesToRadians(double degrees);
double simplifyAngleDegrees(double angle);

#endif