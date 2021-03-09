
#include <stdio.h>
#include "Lab2_1.h"

 enum {
    TANGERIAN,
    PEACHES,
    GRAPE
};

#ifndef TEST

int main() {

    double shoppingCart[] = {0, 0, 0};
    const char *fruitName[] = {"Tangerian", "Peaches", "Grape"};
    const char *Feedback[] = {"\nName of shop: \"eFruit\"\n", 
                              "License number: S01M8-9T53H-1N5U6M\n",
                              "Phone number: +256-41-359-1176\n",
                              "Instagram: @peaches_for_beaches\n"};

    int callMenu = menu(shoppingCart, fruitName, Feedback);

    while(callMenu != 0) {

        if(callMenu == -1) {
            printf("Something really scared has happened...");
            return 0;
        }
        callMenu = menu(shoppingCart, fruitName, Feedback);
    }
    printf("\nGoodbye, thank you for using our shop!\n");
    return 0;
}

#endif

unsigned int getValidUInt() {

    unsigned int temp;
    char goodCheck;

    while(!scanf("%d", &temp) || scanf("%c", &goodCheck) && goodCheck != '\n') {
        printf("Wrong input!\nPlease, try again: ");
        fflush(stdin);
    }

    return temp;
}

double getValidUDouble() {
    
    double temp;
    char goodCheck;

    while(!scanf("%3lf", &temp) ||
          !scanf("%c", &goodCheck) || goodCheck != '\n') {
        printf("Wrong input!\nPlease, try again: ");
        fflush(stdin);
    }

    return temp;
}

double tangerianCost(double tangerianKG)
{   return tangerianKG * TANGERIAN_PRICE_USD;}
double peachesCost(double peachesKG)
{   return peachesKG * PEACHES_PRICE_USD;}
double grapeCost(double grapeKG)
{   return grapeKG * GRAPE_PRICE_USD;}

int menu(double *shoppingCart, const char** fruitName, const char** feedback) {

    unsigned int actionNumber;

    printf("\n\tMenu\n"
       "1)Choose fruit\n"
       "2)Shopping cart\n"
       "3)Total order price\n"
       "4)Complete order\n"
       "5)Contact Information\n"
       "6)Exit\n");

    printf("Action number: ");
    actionNumber = getValidUInt();

    while(actionNumber > 6 || actionNumber <= 0) {
        printf("There are only 5 available actions\nPlease, try again: ");
        actionNumber = getValidUInt();
    }

    switch(actionNumber) {
        case 1:
            chooseFruit(shoppingCart, fruitName);
            break;
        case 2:
            showShoppingCart(shoppingCart, fruitName);
            break;
        case 3:
            showTotalOrderPrice(shoppingCart, fruitName);
            break;
        case 4:
            completeOrder(shoppingCart);
            break;
        case 5:
            showFeedback(feedback);
            break;
        case 6:
            return 0;
        default:
            return -1;
    }
    return 1; 
}

void chooseFruit(double *shoppingCart, const char** fruitName) {

    unsigned int actionNumber;

    printf("what type of fruit do you want?\n"
           "1)Tangerian\n"
           "2)Peaches\n"
           "3)Grape\n");

    printf("Choose fruit: ");
    actionNumber = getValidUInt();

    while(actionNumber > 3 || actionNumber <= 0) {
        printf("There are only 3 type of fruit\nPlease, choose fruit again: ");
        actionNumber = getValidUInt();
    }

    switch(actionNumber) {
        case 1:
            shoppingCart[TANGERIAN] +=
            makeChanges(TANGERIAN, shoppingCart[TANGERIAN], fruitName); 
            break;
        case 2:
            shoppingCart[PEACHES] +=
            makeChanges(PEACHES, shoppingCart[PEACHES], fruitName);
            break;
        case 3:
            shoppingCart[GRAPE] +=
            makeChanges(GRAPE, shoppingCart[GRAPE], fruitName);
            break;
        default:
            return;
    }
}

double makeChanges(int fruiteType, double massOfFruiteType, 
                   const char** fruitName) {

    unsigned int actionNumber;
    double removeMass;

    printf("You have %lf kg of %s\n", massOfFruiteType, fruitName[fruiteType]);
    printf("1)Add fruit\t2)Remove fruit\nAction: ");

    actionNumber = getValidUInt();
    
    while(actionNumber > 2 || actionNumber <= 0) {
        printf("There are only 2 actions\nPlease, try again: ");
        actionNumber = getValidUInt();
    }
    
    if(actionNumber == 1) {
        printf("How much fruit (kg) do you want to add: ");
        return getValidUDouble();
    }
    else {
        return removeFruit(fruitName[fruiteType], massOfFruiteType);
    }
    return 0;
}

double removeFruit(const char* fruiteType, double massOfFruiteType) {

    double removeMass;

    if(massOfFruiteType == 0.0) {
        printf("\nThere are no %s in your cart", fruiteType);
        return 0;
    }

    printf("How much fruit (kg) do you want to remove: ");
    removeMass = getValidUDouble();
    
    while(removeMass > massOfFruiteType){
        printf("You don't have that many fruits"
               "of this type in your basket\nPlease, try again: ");
        removeMass = getValidUDouble();       
    }
    return -removeMass;
}

void showShoppingCart(double *shoppingCart, const char** fruitName) {

    printf("\n\tYour shoping cart\nName\t\t  Mass\t\tPrice\n");

    printf("%-10s%13.3lf%14.3lf$\n",fruitName[TANGERIAN], shoppingCart[TANGERIAN],
                                    tangerianCost(shoppingCart[TANGERIAN]));
    printf("%-10s%13.3lf%14.3lf$\n",fruitName[PEACHES], shoppingCart[PEACHES],
                                    peachesCost(shoppingCart[PEACHES]));
    printf("%-10s%13.3lf%14.3lf$\n",fruitName[GRAPE], shoppingCart[GRAPE],
                                    grapeCost(shoppingCart[GRAPE]));
}

void showTotalOrderPrice(double *shoppingCart, const char** fruitName) {

    showShoppingCart(shoppingCart,fruitName);
    printf("\nFruit cost(without discount)%9.3lf$\n",
            calculateFruitCost(shoppingCart));
    printf("Dicsount%29.2lf%%\n", 100 * 
            (1 - calculateDiscount(shoppingCart)));
    printf("Fruit cost(with discount)%12.3lf$\n",
            calculateFruitCost(shoppingCart) * calculateDiscount(shoppingCart));
    printf("Delivery cost%24d$\n",
            calculateDeliveryPrice(shoppingCart));
    printf("Total order price%20.3lf$\n", calculateTotalOrderPrice(shoppingCart));
}

double calculateTotalOrderPrice(double *shoppingCart) {

    return calculateFruitCost(shoppingCart) * calculateDiscount(shoppingCart) +
                  calculateDeliveryPrice(shoppingCart);
}

double calculateFruitCost(double* shoppingCart) {

    return tangerianCost(shoppingCart[TANGERIAN]) +
           peachesCost(shoppingCart[PEACHES]) +
           grapeCost(shoppingCart[GRAPE]);
}

double calculateDiscount(double* shoppingCart) {

    if (calculateFruitCost(shoppingCart) >= 100) return 0.9;

    return 1.0;
}

int calculateDeliveryPrice(double* shoppingCart) {

    int temp;

    if (shoppingCart[TANGERIAN] + shoppingCart[PEACHES] + 
        shoppingCart[GRAPE] < 5) return 1;
    else if (shoppingCart[TANGERIAN] + shoppingCart[PEACHES] +
             shoppingCart[GRAPE] <= 20) return 3;
        
    temp = ((int) (shoppingCart[TANGERIAN] + shoppingCart[PEACHES] +
            shoppingCart[GRAPE]) - 20) * 2;
    return 10 + temp;
}

void completeOrder(double* shoppingCart) {

    int answer, i;

    if(shoppingCart[TANGERIAN] == 0 && shoppingCart[PEACHES] == 0 &&
       shoppingCart[GRAPE] == 0){
           printf("\nThere is no order");
           return;
       }

    printf("Are you sure?\n"
           "1)Yes\t2)No\n");
    
    answer = getValidUInt();

    while(answer > 2) {
        printf("Wrong input. Please, try again\n"
        "1 - Yes\t2 - No ");
        answer = getValidUInt();
    }
    if(answer == 1) {
        for(i = 0; i < 3; ++i) {
            shoppingCart[i] = 0;  
        }
    }
}

void showFeedback(const char** feedback) {

int i;
for (i = 0; i < 4; ++i) {printf("%s", feedback[i]);}
}