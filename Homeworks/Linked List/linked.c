#include <stdio.h>
#include <stdlib.h>
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
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void Create(LinkedList *list){
    list->head=NULL;
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
        list->head == newNode;
    } else {
        Node *current = list->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }

};

void PopNode(LinkedList *list){
    if (list->head == NULL){
        printf("Sorry but linked list already empty\n");
    } else {
        Node *current = list->head;
        Node *temp = NULL;
        while (current != NULL){
            temp = current;
            current = current->next;
        }
        temp->next = NULL;
        free(current);
    }

};

//void InsertNode(Node node, int position){};

//void DeleteNode(Node node, int position){};

void ShowData(LinkedList *list){
    if (list->head == NULL){
        printf("Linked list is empty\n");
    } else {
        Node *current = list->head;
        while(current != NULL){
            printf("%d -> ",current->data);
            current = current->next;
        }
    }
};

void Help(){
    printf("All allowed commands:\n\
    Create - create new empty Linked List\n\
    Clear - delete linked list\n\
    Print - print data in Linked List\n\
    Add - add node to Linked List\n\
    Pop - delete last node in Linked List\n\
    Insert - insert node to specified position in Linked List\n\
    Delete - delete node on specified position in Linked List\n\
    Exit - leave the programm\n");
};

int main(int argc, char *argv[]){
    char *command = NULL; 
    size_t len = 0; 
    ssize_t nread;
    
    LinkedList bogdan;
    LinkedList *pbogdan = NULL;
    //char *LastCommand = NULL;

    printf("\nHello, to get list of allowed commands print Help \n \
            print Exit or type [ctrl + c] to quit\n");

    while (1){
      //  LastCommand = command;
        printf("I`m waiting for your command\n");
        nread = getline(&command, &len, stdin);

        if (nread == -1){
            perror("Something went wrong, try later, bye \n");
            break;
        }

        if (command[nread-1] == '\n'){
            command[nread-1] = '\0';
        }

        if (strcmp(command,"Exit") == 0) {
            printf("Bye \n");    
            break;
        }
        /*if (strcmp(LastCommand,"Add") == 0){
            AddNode(&bogdan,(int*)*command);
        };*/

        if (strcmp(command,"Help") == 0){
            Help();
        } 
        else if(strcmp(command,"Create") == 0){
            if (pbogdan == &bogdan){
                printf("Sorry,Linked List already created\n");
            } else {
                Create(&bogdan);
                pbogdan = &bogdan;
                printf("Linked List created\n"); 
            }
        }
        else if(strcmp(command,"Clear") == 0){
            if (pbogdan == NULL){
                printf("Sorry,Linked List wasn`t created yet\n");
            } else {
                Clear(&bogdan);
            } 
        }
        else if(strcmp(command,"Print") == 0){
            if (pbogdan == NULL){
                printf("Sorry,Linked List wasn`t created yet\n");
            } else {
                ShowData(&bogdan); 
            } 
        }
        else if(strcmp(command,"Add") == 0){
            if (pbogdan == NULL){
                printf("Sorry,Linked List wasn`t created yet\n");
            } else {
                int data;
                printf("Input int data\n");
                if (scanf("%d", &data) != 1){
                    printf("Sorry,wrong input,try again\n");
                } else {
                    fflush(stdin);
                    AddNode(&bogdan,data); 
                }
           }
        }
        else if(strcmp(command,"Pop") == 0){
            if (pbogdan == NULL){
                printf("Sorry, Linked List wasn`t created yet\n");   
            } else {
                PopNode(&bogdan); 
            }
        }
        /*else if(strcmp(command,"Insert")){
            InsertNode(); 
        }
        else if(strcmp(command,"Delete")){
            DeleteNode(); 
        }*/
        else {
            printf("I don`t know such command, try again\n");
        }

    }
    free (command);  

    return 0;

}
