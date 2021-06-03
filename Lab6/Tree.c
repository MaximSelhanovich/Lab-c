#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int checkPalindrome(const char *word) {
    int i = 0, k;
    int length = 0;

    if (!word) return 0;
    length = strlen(word);
    k = length - 1;

    for (i = 0; i < length / 2; ++i) {
        if (tolower(word[i]) != tolower(word[k])) return 0;
        --k;
    }

    return 1;
}

Node* newEmptyNode() {
    Node *new = (Node*)malloc(sizeof(Node));
    new->word = NULL;
    new->left = new->right = NULL;

    return new;
}

Node* newNode(char *word) {
    Node *new = (Node*)malloc(sizeof(Node));

    if (!new) {
        printf("\nError in creation Node!\n");
    } else {
        new->word = word;
        new->left = new->right = NULL;
    }

    return new;
}

void addNodeWord(Node *root, char *word) {
    Node *new = NULL;

    if (!root) return;

    new = newNode(word);
    if (!new) return;
    addNodeNode(root, new);
}

void addNodeNode(Node *root, Node *newNode) {
    Node *current = root;
    Node *temp = NULL;
    if(!newNode || !root) return;

    while (current) {
        temp = current;
        if (strcmp(newNode->word, current->word) <= 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (strcmp(newNode->word, temp->word) <= 0) {
        temp->left = newNode;
    } else {
        temp->right = newNode;
    }
}

void inOrder(Node *root) {
    if (root->left) inOrder(root->left);

    printf("%s\n", root->word);

    if (root->right) inOrder(root->right);
}

void inOrderPalindrome(Node *root) {
    if (root->left) inOrderPalindrome(root->left);

    if (checkPalindrome(root->word)) printf("%s\n", root->word);

    if (root->right) inOrderPalindrome(root->right);
}

void deleteNode(Node *toDelete) {
    free(toDelete->word);
    free(toDelete);
}

void deleteTree(Node *root) {
    if (!root) return;

    if (root->left) deleteTree(root->left);

    if (root->right) deleteTree(root->right);

    deleteNode(root);
}

Node* deleteTreeNode(Node *root, char *keyWord) {
    Node *temp = NULL;

    if (!root || !keyWord) return NULL;

    if (strcmp(keyWord, root->word) == -1) {
        root->left = deleteTreeNode(root->left, keyWord);
    } else if (strcmp(keyWord, root->word) == 1) {
        root->right = deleteTreeNode(root->right, keyWord);
    }  else {
        if (!root->left && !root->right) {
            temp = root;
            root = NULL;
            return NULL;
        } else if (!root->left) {
            temp = root;
            root = root->right;
        } else if (!root->right) {
            temp = root;
            root = root->left;
        } else {
            temp = root->right;
            while (temp->left) {
                temp = temp->left;
            }
            root->word = temp->word;
            root->right = deleteTreeNode(root->right, temp->word);
        }
    }
    return temp;
}
