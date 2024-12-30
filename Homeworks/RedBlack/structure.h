#include <stdbool.h>

const static bool RED = 1;
const static bool BLACK = 0;

typedef struct Node
{
     int data;
     bool color;
     struct Node* parent;
     struct Node* right;
     struct Node* left;
     char value[10];

} Node;

Node* createNode(const int d,const bool c);
Node* insert(Node* root, Node* new);
void rightrotate(Node* node);
void leftrotate(Node* node);
void balance(Node* root, Node* node);
void inorder(Node* node);
Node* getvalue(Node* node, const int key);


