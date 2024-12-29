#include <stdbool.h>

const static bool RED = 0;
const static bool BLACK = 1;

typedef struct Node{
    int data;
    struct Node *left,*right,*parent;
    bool color;
} Node;

Node* createNode(const int d, const bool c){
    Node *newNode = (Node *)malloc(sizeof(Node));
        
    newNode->data = d;
    newNode->color = c;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
};


