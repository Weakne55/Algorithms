#include <stdio.h>
#include "red_black.h"

void inOrder(RBTree* tree, Node* r)
{
    Node* nil = tree->nil;
    Node* root = tree->root;

    if (r == nil || r == NULL)
        return;
    inOrder(tree, r->left);
    printf("%d\n", r->val);
    inOrder(tree, r->right);
}

int main(int argc, char** argv)
{
    int i, j;
    const int n = 10;
    int* arr = (int*)malloc(n * sizeof(int));
    RBTree* T = (RBTree*)malloc(sizeof(RBTree));
    Node* nil = createNode(-1, BLACK, NULL, NULL, NULL);
    Node* root = nil;
    T->nil = nil;
    T->root = root;

    for (i = 0; i < n; ++i)
        arr[i] = rand();
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\nFinished inserting\n");

    for (i = 0; i < n; ++i) {
        insert(T, arr[i]);
    }
    printf("%d\n", T->root->val);
    inOrder(T, T->root);
    return 0;
}
