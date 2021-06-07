#include <stdlib.h>
#include <stdio.h>
#include "Date.h"
#include "Task.h"


int main() {
    Task *new = getTask();
    printTask(new);

    deleteTask(new);

    return 0;
}