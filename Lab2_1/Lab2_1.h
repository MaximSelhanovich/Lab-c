#ifndef LAB2_1_H
#define LAB2_1_H

unsigned int getValidUInt();
double getValidUDouble();

double tangerianCost(double tangerianKG);
double peachesCost(double peachesKG);
double grapeCost(double grapeKG);

int menu(double *shoppingCart, const char** fruitName, const char** feedback);

void chooseFruit(double *shoppingCart, const char** fruitName);
double makeChanges(int fruiteType, double massOfFruiteType, 
                   const char** fruitName);
double removeFruit(const char* fruiteType, double massOfFruiteType);

void showShoppingCart(double *shoppingCart, const char** fruitName);
void showTotalOrderPrice(double *shoppingCart, const char** fruitName);

double calculateTotalOrderPrice(double *shoppingCart);
double calculateFruitCost(double* shoppingCart);
double calculateDiscount(double* shoppingCart);
int calculateDeliveryPrice(double* shoppingCart);

void completeOrder(double* shoppingCart);

void showFeedback(const char** feedback);

#endif