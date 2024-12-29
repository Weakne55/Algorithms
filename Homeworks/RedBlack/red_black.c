#include "red_black.h"

Node* createNode(const int v, const bool c, Node* l, Node* r, Node* p)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = v;
    newNode->color = c;
    newNode->left = l;
    newNode->right = r;
    newNode->parent = p;
    return newNode;
}

void leftRotate(RBTree* tree, Node* x)
{
    Node* nil = tree->nil;

    Node* y = x->right;
    x->right = y->left;
    if (y->left != nil)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == nil)
        tree->root = y;
    else if (x->parent->left == x)
        x->parent->left = y;
    else
        x->parent->right = y;
    x->parent = y;
    y->left = x;
}

void rightRotate(RBTree* tree, Node* x)
{
    Node* nil = tree->nil;

    Node* y = x->left;
    x->left = y->right;
    if (y->right != nil)
        y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == nil)
        tree->root = y;
    else if (x->parent->left == x)
        x->parent->left = y;
    else
        x->parent->right = y;
    x->parent = y;
    y->right = x;
}

Node* insertBST(RBTree* tree, Node* p, Node* r, const int v)
{
    Node* nil = tree->nil;

    if (r == nil) {
        r = createNode(v, RED, nil, nil, p);
        if (p == nil)
            tree->root = r;
        if (v > p->val)
            p->right = r;
        else
            p->left = r;
    } else {
        if (v < r->val)
            return insertBST(tree, r, r->left, v);
        else
            return insertBST(tree, r, r->right, v);
    }
    return r;
}

void insert(RBTree* tree, const int v)
{
    Node* nil = tree->nil;

    Node* z = insertBST(tree, nil, tree->root, v);
    while (z->parent->color == RED) {
        if (z->parent->parent->left == z->parent) {
            if (z->parent->parent->right->color == RED) {
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                z->parent->parent->right->color = BLACK;
                z = z->parent->parent;
            } else {
                if (z->parent->right == z) {
                    z = z->parent;
                    leftRotate(tree, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(tree, z->parent->parent);
            }
        } else {
            if (z->parent->parent->left->color == RED) {
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                z->parent->parent->left->color = BLACK;
                z = z->parent->parent;
            } else {
                if (z->parent->left == z) {
                    z = z->parent;
                    rightRotate(tree, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(tree, z->parent->parent);
            }
        }
    }
    tree->root->color = BLACK;
}

Node* findMin(RBTree* tree, Node* r)
{
    Node* nil = tree->nil;
    Node* p = r;
    while (r != nil) {
        p = r;
        r = r->left;
    }
    return p;
}

Node* getNode(RBTree* tree, Node* r, const int v)
{
    Node* nil = tree->nil;
    if (r == nil)
        return nil;
    if (r->val == v)
        return r;
    else if (v < r->val)
        return getNode(tree, r->left, v);
    else
        return getNode(tree, r->right, v);
}
