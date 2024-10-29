#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Node {
    int data;
    struct Node *next; //pointer to next node
} Node;


typedef struct LinkedList{
    // we need head
    Node head;

} LinkedList;

void Showll(char* listofnames){}

void Choosell(char* namell, char* listofnames){}

void Createll(char* namell, char* listofnames){}

void Deletell(LinkedList namell){}

void AddNode(LinkedList namell){}

void PopNode(Node node){}

void InsertNode(Node node, int position){}

void DeleteNode(Node node, int position){}

void ShowData(LinkedList namell){}

void Check(LinkedList namell){

}

void Help(){
    printf("All allowed commands:\n\
    Show - show all created Linked Lists\n\
    Choose - choose Linked List you want work with\n\
    Create - create new empty Linked List\n\
    Clear - delete chosen linked list\n\
    Check - show chosen Linked List\n\
    Print - print data in choden Linked List\n\
    Add - add node to chosen Linked List\n\
    Pop - delete last node in chosen Linked List\n\
    Insert - insert node to specified position in chosen Linked List\n\
    Delete - delete node on specified position in chosen Linked List\n\
    Exit - leave the programm");
}

int main(int argc, char *argv[]){
    // While we dont get stop-word we can manipulate with LinkedList, we need var:command
    // infinite input: while command is not 'exit' and if input not in list of commands, then print(Sorry,idk what do you want)
    // else: run command (function)
    // List of commands: ['show ll','choose ll','create ll','delete ll','add node'(assumed add data to chosen before node),
    // 'pop node'(assumed to pop node in chosen ll),'show data'(show all nodes in chosen ll:data1->data2->data3)]
    // So we need comand to make linked-list and we should can several linked list at one program
    // show ll: [LinkedList1, LinkedList2, ...]  or None if ll is empty
    // choose ll - assign input to var: chosenll, then check if chosenll in ll
    // 
    char *ListOfCommands[] = {"Show", "Choose","Create","Clear","Check","Print","Add","Pop","Insert","Delete","Exit"};


    char *command = NULL; // forces getline to allocate with malloc 
    size_t len = 0; 
    ssize_t read;

    printf ("\nHello, to get list of allowed commands print Help \n \
            print Exit or type [ctrl + c] to quit\n");


    while ((read = getline(&command, &len, stdin)) != -1) {

        if (read > 0)
            printf ("\nYou entered\n %s\n", command);

        printf ("Enter string below [ctrl + c] to quit\n");
    }

    free (command);  /* free memory allocated by getline */

    return 0;

}
