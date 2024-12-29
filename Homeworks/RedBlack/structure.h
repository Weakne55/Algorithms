
const static int RED = 1;
const static int BLACK = 0;

typedef struct Node
{
     int data;
     int color;
     struct Node* = left,right,parent;

} Node;

Node* createNode(const int d,const bool c);


