#pragma once
#include <stdbool.h>
#include <stdlib.h>

const static bool RED = 0;
const static bool BLACK = 1;

typedef struct Node
{
    int val;
    bool color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

Node* createNode(const int v, const bool c, Node* l, Node* r, Node* p);

typedef struct RBTree
{
    Node* nil;
    Node* root;
} RBTree;

void leftRotate(RBTree* tree, Node* x);
void rightRotate(RBTree* tree, Node* x);
Node* insertBST(RBTree* tree, Node* p, Node* r, const int v);
void insert(RBTree* tree, const int v);
Node* findMin(RBTree* tree, Node* r);
Node* getNode(RBTree* tree, Node* r, const int v);
