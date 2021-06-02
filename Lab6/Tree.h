#ifndef TREE_H
#define TREE_H

typedef struct Node {
    char *word;
    struct Node *left;
    struct Node *right;
}Node;

int checkPalindrome(const char *word);

Node* newEmptyNode();

Node* newNode(char *word);

void addNodeWord(Node *root, char *word);

void addNodeNode(Node *root, Node *newNode);

void inOrder(Node *root);

void inOrderPalindrome(Node *root);

void deleteTree(Node *root);

void fillTree(Node *root);

Node* deleteTreeNode(Node *root, char *keyWord);
#endif