#include "Lab2_1.h"

#include <stdio.h>
#include <float.h>
#include <assert.h>

void testFruitCosts() {

    assert(tangerianCost(5) - TANGERIAN_PRICE_USD * 5  < DBL_EPSILON);
    assert(peachesCost(5) - PEACHES_PRICE_USD * 5  < DBL_EPSILON);
    assert(grapeCost(5) - GRAPE_PRICE_USD * 5  < 0.000000000001);
    printf("Costs test are succsesful.\n");
}

void testcalculateFruitCost() {

    double testFruitCost[] = {5, 5, 5};
    assert(calculateFruitCost(testFruitCost) - 17.1 < DBL_EPSILON);
    printf("Fruit cost test comlete.\n");
}

void testCalculateDiscount() {

    double testDiscount1[] = {5, 5, 5};
    double testDiscount2[] = {100, 100, 100};
    assert(calculateDiscount(testDiscount1) - 1.0 < DBL_EPSILON);
    assert(calculateDiscount(testDiscount2) - 0.9 < DBL_EPSILON);
    printf("Discaunt test complete.\n");    
}

void testCalculateDeliveryPrice() {

    double testDelivery1 [] = {1, 1, 1};
    double testDelivery2 [] = {5, 5, 5};
    double testDelivery3 [] = {10, 10, 10};
    assert(calculateDeliveryPrice (testDelivery1) - 1 < DBL_EPSILON);
    assert(calculateDeliveryPrice (testDelivery2) - 3 < DBL_EPSILON);
    assert(calculateDeliveryPrice (testDelivery3) - 30 < DBL_EPSILON);
    printf("Delivery test complete.\n");
}

void testcalculateTotalOrderPrice() {

    double testOrderPrice1[] = {1, 1, 1};
    double testOrderPrice2[] = {5, 5, 5};
    double testOrderPrice3[] = {10, 10, 10};
    double testOrderPrice4[] = {100, 100, 100};
    assert(calculateTotalOrderPrice(testOrderPrice1) - 4.42 < DBL_EPSILON);
    assert(calculateTotalOrderPrice(testOrderPrice2) - 20.1 < DBL_EPSILON);
    assert(calculateTotalOrderPrice(testOrderPrice3) - 64.2 < DBL_EPSILON);
    assert(calculateTotalOrderPrice(testOrderPrice4) - 912 < DBL_EPSILON);
    printf("Test order price complete.\n");
}

#undef main

int main() {

    testFruitCosts();
    testcalculateFruitCost();
    testCalculateDiscount();
    testCalculateDeliveryPrice();
    testcalculateTotalOrderPrice();
    printf("\nAll tests are complited succesfuly.\n");
}