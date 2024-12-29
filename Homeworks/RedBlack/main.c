#include <stdio.h>
#include "red_black.h"

void inOrder(RBTree* tree, Node* r)
{
    Node* nil = tree->nil;
    Node* root = tree->root;

    if (r == nil || r == NULL)
        return;
    inOrder(tree, r->left);
    printf("%d ", r->val);
    if (r->color == RED)
        printf("RED\n");
    else
        printf("BLACK\n");

    inOrder(tree, r->right);
}


int height(Node* node, Node* nil)
{
    if (node == nil)
        return 0;
    else {
        int lheight = height(node->left, nil);
        int rheight = height(node->right, nil);
        return (lheight > rheight) ? (lheight + 1) : (rheight + 1);
    }
}

void printCurrentLevel(Node* root, Node* nil, int level)
{
    if (root == nil)
        return;
    if (level == 1) {
        printf("(%d, ", root->val);
        if (root->color == RED)
            printf("RED) ");
        else
            printf("BLACK) ");
    } else if (level > 1) {
        printCurrentLevel(root->left, nil, level - 1);
        printCurrentLevel(root->right, nil, level - 1);
    }
}

void printLevelOrder(Node* root, Node* nil)
{
    int i;
    int h = height(root, nil);
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, nil, i);
}

int main(int argc, char** argv)
{
    int i;
    const int n = 5;
    int arr[] = {5, 3, 2, 1, 4};
    RBTree* T = (RBTree*)malloc(sizeof(RBTree));
    Node* nil = createNode(-1, BLACK, NULL, NULL, NULL);
    Node* root = nil;
    T->nil = nil;
    T->root = root;

    for (i = 0; i < n; ++i)
        insert(T, arr[i]);

    // inOrder(T, T->root);
    printLevelOrder(T->root, nil);
    printf("\n");
    return 0;
}
