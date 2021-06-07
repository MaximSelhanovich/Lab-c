#include <stdlib.h>
#include <stdio.h>
#include "Date.h"


int main() {
    Date *new = getDate();
    printDate(new);

    deleteDate(new);

    return 0;
}