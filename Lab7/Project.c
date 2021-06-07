#include "ListOfTasks.h"

typedef struct Project {
    ListOfTasks *criticalTasks;
    ListOfTasks *parallelTasks;
    char *projectName;
    int peopleOnProject;
    double ResourcesOnProject;
}Project;