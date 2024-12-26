#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next; 
} Node;


typedef struct LinkedList{
    Node *head;
} LinkedList;

Node* createNode(int data){
    //printf("New Node created\n");
    Node *newNode = (Node *)malloc(sizeof(Node));
    /*if (newNode == NULL){
        printf("Sorry, pointer is NULL\n");
    } else {
        printf("%p\n", newNode);
    }*/
    
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};

void Create(LinkedList *list){
    if (list->head == NULL){
        printf("Linked List already initialized\n");
    }
    else {
        printf("Linked List created\n");
        list->head=NULL;
    }
};

void Clear(LinkedList *list){
    Node *current = list->head;
    Node *nextNode;
    while(current != NULL){
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    list->head = NULL;
};

void AddNode(LinkedList *list,int data){
    Node *newNode = createNode(data);
    if (list->head == NULL){
        list->head = newNode;
        //printf("%p, newNode memory adress\n", newNode);
        //printf("We added new Node to head\n");
        //printf("%p, pointer of head\n",list->head);
    } else {
        //printf("We are going to add Node into the end\n");
        Node *current = list->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
        //printf("We added node to tail\n");
    }

};

void PopNode(LinkedList *list){
    if (list->head == NULL){
        printf("Sorry but linked list already empty\n");
    } else {
        Node *current = list->head;
        Node *temp = NULL;
        while (current->next != NULL){
            temp = current;
            current = current->next;
        };
        //printf("%d %p\n",temp->data, current);
        printf("%d\n",current->data);
        temp->next = NULL;
        free(current);
    }

};

void InsertNode(LinkedList *list, int data, int position){
    int k = 1;
    if (list->head == NULL){
        printf("Linked List is empty");
    }
    else{
        Node *current = list->head;
        while(current != NULL){
            ++k;
            
        };
    }
};

void DeleteNode(LinkedList *list, int position){
    int i = 0;
    Node *current = list->head;
    Node *tmp = NULL;
    if (list->head == NULL){
        printf("Sorry but linked list already empty\n");
    } else {
        if (position == 1){
            PopNode(list);
        }
        else{
            
        }
 
};

void ShowData(LinkedList *list){
    if (list->head == NULL){
        printf("Linked list is empty\n");
    } else {
        Node *current = list->head;
        while(current != NULL){
            printf("%d -> ",current->data);
            current = current->next;
        };
        printf("\n");

    }
};

int main(int argc, char *argv[]){

    LinkedList list;
    Create(&list);
    //Create(&list);
    AddNode(&list,10);
    //printf()
    //ShowData(&list);

    for (int i = 0; i<=5; ++i){
        AddNode(&list, i);
    }
    
    ShowData(&list);
    PopNode(&list);
    ShowData(&list);
    Clear(&list);
    ShowData(&list);
 
    return 0;

}
