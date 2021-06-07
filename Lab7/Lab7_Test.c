#include "Date.h"
#include "Task.h"
#include "ListOfTasks.h"
#include "assert.h"

void testgetDate() {
    /*321\n2024\n-4\n2\nasdf\n29\n*/    
    Date *test = getDate();
    assert(test);
    assert(test->year == 2024);
    assert(test->month == 2);
    assert(test->day == 29);

    assert(printDate(test));
    assert(!printDate(NULL));
    
    deleteDate(test);
}

void testgetMaxDay() {
    assert(getMaxDay(-4) == INT_MIN);
    assert(getMaxDay(4) == 30);
    assert(getMaxDay(2) == 28);
    assert(getMaxDay(5) == 31);
}

void testdifDate(Date* start, Date* end) {
    /*2022\n5\n28\n*/
    Date *test1 = getDate();
    /*2026\n6\n30\n*/
    Date *test2 = getDate();
    /*2026\n6\n30\n*/

    assert(difDate(test1, test2) == 1495);
    assert(difDate(NULL, test2) == INT_MIN);
    assert(difDate(test1, NULL) == INT_MIN);

    rewriteDate(test1);

    assert(compareDate(test1, test2) == -1);
    assert(compareDate(test2, test1) == 1);
    assetr(!compareDate(test2, test1));

    deleteDate(test1);
    deleteDate(test2);
}

void testgetTask() {
    /*Get rekted\n2222\n2\n2\n2222\n\1\n1\n2345\n2\n2\n*/
    Task *task = getTask();
    
    assert(!strcmp(task->startTaskTime, "Get rekted"));

    assert(task->startTaskTime->year == 2222);
    assert(task->startTaskTime->month == 2);
    assert(task->startTaskTime->day == 2);

    assert(task->endTaskTime->year == 2345);
    assert(task->endTaskTime->year == 2);
    assert(task->endTaskTime->year == 2);

    assert(!printTask(NULL));
    assert(printTask(task));

    deleteTask(task);
}

void testListOfTasks() {

    ListOfTasks *list = newListOfTasks();
    /*Architector\n2211\n12\n30\n2222\n5\n18\n*/
    Task *task1 = getTask();
    addTaskEnd(list, task1);

    /*Domachnee zadanie\n2022\n02\n21\n2030\n09\n30\n*/
    Task *task2 = getTask();
    addTaskFront(list, task2);

    /*Zhmuh\n2057\n9\n3\n2089\n6\n2\n*/
    Task *task3 = getTask();
    addTask(list, task3);

    /*Ocheredi\n2045\n8\n3\n2046\n8\n3\n*/
    Task *task4 = getTask();
    addTask(list, task4);
    

    deleteListOfTasks(list);
}


#undef main

int main() {



}