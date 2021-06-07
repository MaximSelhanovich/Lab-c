#include "Date.h"

/*These functiion can be used for day, month and year*/
int getValidInt(int minValue, int maxValue) {
    int temp;
    char goodCheck;

    while(!scanf("%d", &temp) || temp < minValue || temp > maxValue ||
          (scanf("%c", &goodCheck) && goodCheck != '\n')) {
        printf("Wrong input!\nDate must be >= %d && <= %d.\n"
               "Please, try again: ",minValue, maxValue);
        fflush(stdin);
    }

    return temp;
}

int getMaxDay(Month month) {
    if (month < 0 || month > 12) return INT_MIN;

    if (month == February) return 28;

    if (month == April || month == June || month == September ||
        month == November)
        return 30;

    return 31;
}

int rewriteDate(Date *toRewrite) {
    char temp = 0;
    
    if (!toRewrite) return 0;

    printf("\nEnter year(2021 - 3000): ");
    toRewrite->year = getValidInt(2021, 3000);

    printf("\nEnter month(1 - 12): ");
    toRewrite->month = getValidInt(1, 12);

    temp = getMaxDay(toRewrite->month);
    if (toRewrite->month == February && toRewrite->year % 4) ++temp;
    
    printf("\nEnter day(1 - %d): ", temp);
    toRewrite->day = getValidInt(1, temp);

    return 1;
}

Date* getDate() {
    Date *received = NULL;

    received = (Date*)malloc(sizeof(Date));
    if (!received) {
        printf("\nError in allocation memory in \"Date\"\n");
        exit(1);
    }

    rewriteDate(received);

    return received;
}

/*It returns days*/
int difDate(Date* start, Date* end) {
    int diff = 0;
    int i = 0;

    if (!start || !end) {
        printf("\nError, \"Date\" is missing\n");
        return INT_MIN;
    }

    if (!(start->year % 4) && start->month <= February)
        ++diff;

    for (i = start->year + 1; i < end->year; ++i) {
        if (i % 4 == 0) ++diff;
    }

    if (!(end->year % 4) &&
        (end->month > February ||
        (end->month == February && end->day == 29)))
        ++diff;
     
    diff += (end->year - end->year) * 365 +
            getMaxDay(end->month) - getMaxDay(end->month +
            end->day - start->day);
    
    return diff;
}

int compareDate(Date *first, Date *second) {
    if (first->year < second->year) return -1;
    else if (first->year > second->year)
        return 1;

    if (first->month < second->month) return -1;
    else if (first->month > second->month)
        return 1;

    if (first->day < second->day) return -1;
    else if (first->day > second->day)
        return 1;

    return 0;
}

int printDate(Date *date) {
    if (!date) return 0;

    printf("%02d.%02d.%d", date->day, date->month, date->year);

    return 1;
}

void deleteDate(Date *date) { free(date); }

/*typedef enum DayInMonth {
    January = 31,
    February = 28,
    March = 31,
    April = 30,
    May = 31,
    June = 30,
    July = 31,
    August = 31,
    September = 30,
    October = 31,
    November = 30,
    December = 31,
}DayInMonth;*/