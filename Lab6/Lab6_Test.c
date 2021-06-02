#include "Lab6.h"
#include <assert.h>

void testcheckEndInput() {
    assert(!checkEndInput("QWE"));
    assert(checkEndInput("end"));
    assert(checkEndInput("EnD"));
    assert(!checkEndInput("89456132"));

    printf("checkEndInput test complited.\n");
}

void testgetWord() {
    char *testLine = NULL;
    
    testLine = getWord();
    printf("\n%s\n", testLine);
    assert(strcmp(testLine, "my word"));
    free(testLine);
    
    testLine = getWord();
    assert(strcmp(testLine, "Say my name"));
    free(testLine);

    printf("getWord test complited\n");
}

void testfillTree() {
    Node *testTree = newEmptyNode();
    Node *current = testTree;
    if (!testTree) return;

    fillTree(testTree);

    assert(strcmp(current->word, "klop"));
    current = current->left;
    assert(!strcmp(current->word, "doom"));
    current = current->left;
    assert(strcmp(current->word, "aboba"));
    current = testTree->left->right;
    assert(strcmp(current->word, "hi"));
    current = testTree->right;
    assert(strcmp(current->word, "onion"));
    current = testTree->right;
    assert(strcmp(current->word, "topor"));
    current = testTree->right->left;
    assert(strcmp(current->word, "mork"));

    deleteTree(testTree);
    printf("fillTree test complited\n");
}

void testcheckPalindrome() {
    assert(!checkPalindrome(NULL));
    assert(checkPalindrome("LoL"));
    assert(!checkPalindrome("notPalus"));
    assert(checkPalindrome("veveevev"));

    printf("checkPalindrome test complited\n");
}
#undef main

int main() {
    testcheckEndInput();
    testgetWord();
    testfillTree();
    testcheckPalindrome();

    return 0;
}
