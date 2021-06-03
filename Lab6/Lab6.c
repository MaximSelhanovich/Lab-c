#include "Lab6.h"

int main() {
    Node *root = newEmptyNode();
    fillTree(root);

    inOrderPalindrome(root);
    deleteTree(root);
    return 0;
}

int checkEndInput(char *word) {
    int i = 0;
    const char *keyWord = "end";
    if (!word) return 0;

    if (strlen(word) != strlen(keyWord)) return 0;

    for (i = 0; i < strlen(keyWord); ++i) {
        if (tolower(word[i]) != keyWord[i]) return 0;
    }

    return 1;
}

char* resizeLine(char *line) {
    char *tempLine = NULL;
    unsigned int length = strlen(line);

    tempLine = (char*)realloc(line, (length + 1) * sizeof(char));
    if (!tempLine) return line;

    tempLine[length] = '\0';

    return tempLine;
}

char* getWord() {
    char *tempLine = (char*)malloc(256 * sizeof(char));
    if (!tempLine) return NULL;

    scanf("%[^\n]255s", tempLine);
    scanf("%*c");
    tempLine = resizeLine(tempLine);
    return tempLine;
}

void fillTree(Node *root) {
    char *tempLine = NULL;
    if (!root) return;

    printf("\nEnter \"end\" as a new word to finish process\n");
    tempLine = getWord();

    while (!checkEndInput(tempLine)) {
        if (!root->word) root->word = tempLine;
        else
            addNodeWord(root, tempLine);

        tempLine = getWord();
    }
    free(tempLine);
}
