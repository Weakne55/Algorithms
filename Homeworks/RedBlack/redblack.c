#include "structure.c"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n = 4;
    int a[4] = { 10, 20, 30, 15 };
 
    for (int i = 0; i < n; i++) {
 
        Node* temp
            = (Node*)malloc(sizeof(Node));
        temp->right = NULL;
        temp->left = NULL;
        temp->parent = NULL;
        temp->data = a[i];
        temp->color = true;
        strcpy(temp->value , "empty");
 
        root = insert(root, temp);
 
        balance(root, temp);
    }

    Node* keynode = (Node*)malloc(sizeof(Node));
    keynode->right = NULL;
    keynode->left = NULL;
    keynode->parent = NULL;
    keynode->data = 17;
    keynode->color = true;
    strcpy(keynode->value , "Secret!");

    root = insert(root,keynode);
    balance(root, keynode);
 
    printf("Inorder Traversal of Created Tree\n");
    inorder(root);
    
    Node* answer = getvalue(root, 17);
    if (answer != NULL)
        printf("%s\n", answer->value);
    else
        printf("Такого ключа нет");
    return 0;
}
