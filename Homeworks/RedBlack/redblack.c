#include <stdio.h>
#include "structure.h"


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
    Node->left = left->right; 
    if (Node->left) // если есть правый потомок (node->left->right) левого потомка (node->left)
        Node->left->parent = node; // то его родитель (node->left->right->parent) теперь это не левый потомок, а node
    left->parent = Node->parent; // родитель копии node->left теперь родитель самого node
    if (!Node->parent) // если оказалось, что у node нет родителя, т.е. он root
        root = left; // то теперь root это left,т.е. Node->left стал корнем. Ссылка на node остается в node.left.parent
    else if (Node == node->parent->left) // если наша нода была левой, то 
        Node->parent->left = left; // то теперь левой будет node.left
    else
        Node->parent->right = left; // если правой, то правой будет node.left
    left->right = Node; // убираем одну связь на правую ноду, т.к. сейчас их 2
    Node->parent = left; // привязываем parent нашей ноды к её прошлому левому узлу
}


void leftrotate(Node* node ) //аналогично для правого поворота
{
    Node* right = node->right;
    Node->right = right->left;
    if (Node->right)
        Node->right->parent = node;
    right->parent = Node->parent;
    if (!Node->parent)
        root = right;
    else if (Node == node->parent->left)
        Node->parent->left = right;
    else
        Node->parent->right = right;
    right->left = Node;
    Node->parent = right;
}


void balance(Node* root, Node* node)
{
    Node* parent_node = NULL; // указатели на деда и родителя
    Node* grand_parent_node = NULL;
 
    while ((node != root) && (node->color != 0) && (node->parent->color == 1))
    { // пока вершина не корень и пока её цвет красный-1, и пока цвет её родителя красный-1
        parent_node = node->parent; // получаем указатели на родителя и деда
        grand_parent_node = node->parent->parent;
 
        /*  Case : A
             Родитель node - left child деда
        */
        if (parent_node == grand_parent_node->left) // проверяем это
        {
 
             Node* uncle_node = grand_parent_node->right; // создаем ноду дяди, которая будет правая для деда
 
            /* Case : 1
                The uncle of pt is also red
                Only Recoloring required */
            if (uncle_pt != NULL && uncle_pt->color == 1) 
            {
                grand_parent_pt->color = 1;
                parent_pt->color = 0;
                uncle_pt->color = 0;
                pt = grand_parent_pt;
            }
 
            else {
 
                /* Case : 2
                     pt is right child of its parent
                     Left-rotation required */
                if (pt == parent_pt->right) {
                    leftrotate(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
 
                /* Case : 3
                     pt is left child of its parent
                     Right-rotation required */
                rightrotate(grand_parent_pt);
                int t = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->c = t;
                pt = parent_pt;
            }
        }
 
        /* Case : B
             Родитель ноды - правый ребенок деда
        */
        else {
             Node* uncle_pt = grand_parent_pt->left;
 
            /*  Case : 1
                The uncle of pt is also red
                Only Recoloring required */
            if ((uncle_pt != NULL) && (uncle_pt->color == 1)) 
            {
                grand_parent_pt->color = 1;
                parent_pt->color = 0;
                uncle_pt->color = 0;
                pt = grand_parent_pt;
            }
            else {
                /* Case : 2
                   pt is left child of its parent
                   Right-rotation required */
                if (pt == parent_pt->left) {
                    rightrotate(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
 
                /* Case : 3
                     pt is right child of its parent
                     Left-rotation required */
                leftrotate(grand_parent_pt);
                int t = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = t;
                pt = parent_pt;
            }
        }
    }
}
 

int main(Node* root,int data){
    Node* root = NULL;
    
    
}
