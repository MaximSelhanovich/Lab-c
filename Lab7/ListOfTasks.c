#include "ListOfTasks.h"

ListOfTasks* newListOfTasks() {
    ListOfTasks *list = (ListOfTasks*)malloc(sizeof(ListOfTasks));

    if (!list) {
        printf("\nError in memory allocation in \"ListOfTasks\"\n");
        exit(1);
    }

    list->head = list->tail = NULL;
    list->length = 0;
}

void addTask(ListOfTasks *list, Task *newTask) {
    Task *temp = NULL;

    if (!list || !newTask) return;

    temp = list->head;

    if (compareDate(newTask->startTaskTime, temp->endTaskTime) == -1) {
        addTaskFront(list, newTask);
    }

    while (temp) {
        if (compareDate(newTask->startTaskTime, temp->endTaskTime) != -1) {
            if (temp == list->head) {
                addTaskFront(list, newTask);
            } else if (temp == list->tail) {
                addTaskEnd(list, newTask);
            } else {
                newTask->nextTask = temp->nextTask;
                newTask->prevTask = temp;
                temp->nextTask->prevTask = newTask;
                temp->nextTask = newTask;
            }
            return;
        }

        temp = temp->nextTask;
    }      
}

void addTaskEnd(ListOfTasks *list, Task *newTask) {
    if (!list || !newTask) return;

    if (!list->head) {
        list->head = newTask;
    } else {
        newTask->prevTask = list->tail;
        list->tail->nextTask = newTask;
    }

    ++list->length;
    list->tail = newTask;
}

void addTaskFront(ListOfTasks *list, Task *newTask) {
    if (!list || !newTask) return;

    if (!list->head) {
        list->tail = newTask;
    } else {
        newTask->nextTask = list->head;
        list->head->prevTask = newTask;
    }


    ++list->length;
    list->head = newTask;
}

void removeTaskEnd(ListOfTasks *list) {
    Task *oldTail = NULL;
    
    if (!list || !list->tail) return;

    oldTail = list->tail;
    list->tail = list->tail->prevTask; 

    if (!list->tail) list->head = NULL;
    else
        list->tail->nextTask = oldTail->nextTask;

    --list->length;
    free(oldTail);
}

void removeTaskFront(ListOfTasks *list) {
    Task *oldHead = NULL;

    if (!list || !list->head) return;

    oldHead = list->head;
    list->head = list->head->nextTask;

    if (!list->head) list->tail = NULL;
    else
        list->head->prevTask = oldHead->prevTask;

    --list->length;
    free(oldHead);
}

int searchTask(ListOfTasks *list, const char *nameToSearch) {
    Task *temp = NULL;
    if (!list || !nameToSearch) return 0;

    temp = list->head;

    while (temp) {
        if (!strcmp(temp->taskName, nameToSearch)) {
            printTask(temp);
            return 1;
        }
        temp = temp->nextTask;
    }

    return 0;
}

Task *deleteTaskInList(ListOfTasks *list, const char *nameToSearch) {
    Task *temp = NULL;

    if (!list || !list->head || !nameToSearch) return;

    temp = list->head;

    while (temp) {
        if (!strcmp(temp->taskName, nameToSearch)) {
            printTask(temp);
            
            if (temp == list->head) {
                list->head = list->head->nextTask;
                list->head->prevTask = temp->prevTask;
            } else if (temp == list->tail) {
                list->tail = list->tail->prevTask;
                list->tail->nextTask = temp->nextTask;
            } else {
                temp->prevTask->nextTask = temp->nextTask;
                temp->nextTask->prevTask = temp->prevTask; 
            }
            
            temp->nextTask = temp->prevTask = NULL;
            return temp;
        }
        temp = temp->nextTask;
    }
}

void deleteListOfTasks(ListOfTasks *list) {
    Task *temp = NULL;

    if (!list) return;

    temp = list->head;

    while (list->head) {
        temp = list->head->nextTask;
        deleteTask(list->head);
        list->head = temp;
    }

    free(list);
}

int printListOfTasks(ListOfTasks *list) {
    Task *temp = NULL;

    if (!list) return 0;

    temp = list->head;
    
    printf("\nCurrent tasks");
    while (temp) {
        printTask(list->head);
        temp = temp->nextTask;
    } 

    return 1;
}
