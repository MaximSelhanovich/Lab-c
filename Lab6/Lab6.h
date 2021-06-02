#ifndef LAB6_H
#define LAB6_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Tree.h"

int checkEndInput(char *word);

char* resizeLine(char *line);

char* getWord();

void fillTree(Node *root);

#endif