typedef void * T;


typedef struct node
{
    struct node * next;
    struct node * prev;
    T element;
} Node;

typedef struct list
{
    Node * first;
    Node * last;
    int count;
} List;

Node * first(List * list);
Node * last(List * list);
List * newList();
Node * addLast(List * list, T element);
Node * addFirst(List * list, T element);
Node * getNode(List * list, T element);
void removeNode(List * list, Node * node);
void disposeList(List * list);
void foreach(List * list, void * funcpointer(T));




