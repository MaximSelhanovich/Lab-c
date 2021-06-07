#ifndef TASK_H
#define TASK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Date.h"

typedef struct Task{
    Date *startTaskTime;
    Date *endTaskTime;

    char *taskName;

    struct Task *nextTask;
    struct Task *prevTask; 

}Task;

char* resizeLine(char *line);
char* getWord();

Task *getTask();
void deleteTask(Task *task);
int printTask(Task *task);

#endif