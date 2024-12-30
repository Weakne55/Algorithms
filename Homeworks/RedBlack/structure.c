#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

Node* root = NULL;

Node* createNode(const int d,const bool c)
{  
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = d;
    newNode->color = c;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

// вставка как в бинарное дерево
Node* insert(Node* root, Node* new)
{   
    //расписано в блокноте
    if (root == NULL)
        return new;
 
    if (new->data < root->data) 
    {
        root->left = insert(root->left, new);
        root->left->parent = root;
    }
    else if (new->data > root->data) 
    {
        root->right = insert(root->right, new);
        root->right->parent = root;
    }

    return root;
}

// тут надо рисовать чтобы объяснить :(
void rightrotate(Node* node)
{
    Node* left = node->left;
    node->left = left->right; 
    if (node->left) // если есть правый потомок (node->left->right) левого потомка (node->left)
        node->left->parent = node; // то его родитель (node->left->right->parent) теперь это не левый потомок, а node
    left->parent = node->parent; // родитель копии node->left теперь родитель самого node
    if (!node->parent) // если оказалось, что у node нет родителя, т.е. он root
        root = left; // то теперь root это left,т.е. Node->left стал корнем. Ссылка на node остается в node.left.parent
    else if (node == node->parent->left) // если наша нода была левой, то 
        node->parent->left = left; // то теперь левой будет node.left
    else
        node->parent->right = left; // если правой, то правой будет node.left
    left->right = node; // убираем одну связь на правую ноду, т.к. сейчас их 2
    node->parent = left; // привязываем parent нашей ноды к её прошлому левому узлу
}


void leftrotate(Node* node) //аналогично для правого поворота
{
    Node* right = node->right;
    node->right = right->left;
    if (node->right)
        node->right->parent = node;
    right->parent = node->parent;
    if (!node->parent)
        root = right;
    else if (node == node->parent->left)
        node->parent->left = right;
    else
        node->parent->right = right;
    right->left = node;
    node->parent = right;
}


void balance(Node* root, Node* node)
{
    Node* parent_node = NULL; // указатели на деда и родителя
    Node* grand_parent_node = NULL;
 
    while ((node != root) && (node->color != BLACK) && (node->parent->color == RED))
    { // пока вершина не корень и пока её цвет красный-1, и пока цвет её родителя красный-1
        parent_node = node->parent; // получаем указатели на родителя и деда
        grand_parent_node = node->parent->parent;
 
        /*  Case : A
             Родитель node - левый ребёнок деда
        */
        if (parent_node == grand_parent_node->left) // проверяем это
        {
 
             Node* uncle_node = grand_parent_node->right; // создаем ноду дяди, которая будет правая для деда
 
            /* Case : 1
                Дядя ноды также красный - нужно только перекрасить, так мы перекрасим всё до корня и покрасим потом деда в черный
            */
            if (uncle_node != NULL && uncle_node->color == RED) 
            { // дядя не отсутствует и его цвет красный
                grand_parent_node->color = RED; // тогда цвет деда красный
                parent_node->color = BLACK; // цвет родителя черный
                uncle_node->color = BLACK; // цвет дяди черный
                node = grand_parent_node; // меняем указатель на деда 
            }
 
            else {
 
                /* Case : 2
                     Нода - правый ребенок родителя. Нужно сделать левый поворот
                */
                if (node == parent_node->right) {
                    leftrotate(parent_node); // тут надо рисовать 
                    node = parent_node; // после поворота надо обменять указатели
                    parent_node = node->parent; 
                }
 
                /* Case : 3
                Нода - левый ребенок родителя. Нужно сделать правый поворот
                */
                rightrotate(grand_parent_node); 
                bool t = parent_node->color; // получаем цвет родителя
                parent_node->color = grand_parent_node->color; // обмениваем цвета деда и родителя 
                grand_parent_node->color = t; // 
                node = parent_node; // поднимаемся на ноду выше
            }
        }
 
        /* Case : B
             Родитель ноды - правый ребенок деда
        */
        else {
             Node* uncle_node = grand_parent_node->left;
 
            /*  Case : 1
                Дядя ноды красный.Перекрашиваем
            */
            if ((uncle_node != NULL) && (uncle_node->color == RED)) 
            {
                grand_parent_node->color = RED;
                parent_node->color = BLACK;
                uncle_node->color = BLACK;
                node = grand_parent_node;
            }
            else {
                /* Case : 2
                   Ноды - левый ребёнок родителя. Правый поворт
                */
                if (node == parent_node->left) {
                    rightrotate(parent_node);
                    node = parent_node;
                    parent_node = node->parent;
                }
 
                /* Case : 3
                     Нода - правый ребёнок родителя. Левый поворот
                */
                leftrotate(grand_parent_node);
                bool t = parent_node->color;
                parent_node->color = grand_parent_node->color;
                grand_parent_node->color = t;
                node = parent_node;
            }
        }
    };
    root->color = BLACK;
}

void inorder(Node* node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d\n", node->data);
    inorder(node->right);
}

Node* getvalue(Node* node, const int key)
{
    if (node == NULL || node->data == key)
       return node;
    if (node->data < key)
        getvalue(node->right, key);
    else
        getvalue(node->left, key);
};
 
