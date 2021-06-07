#ifndef DATA_H
#define DATA_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef enum Month {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
}Month;

typedef struct Date{
    int day;
    int month;
    int year;
}Date;

int getValidInt(int minValue, int maxValue);
int getMaxDay(Month month);
int rewriteDate(Date *toRewrite);
Date* getDate();
int difDate(Date* start, Date* end);
int compareDate(Date *first, Date *second);
int printDate(Date *date);
void deleteDate(Date *date);
#endif