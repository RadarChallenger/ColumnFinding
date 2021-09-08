#ifndef ADT_H
#define ADT_H

typedef struct node *Node;
typedef struct list *List;


// function takes x, y coordinate
// return column node
Node newNode(int x, int y);

// return empty column list
List newList(void);

// given list, free all column in list
void freeList(List l);

// add node to the tail of given list
void append(List l, int x, int y);

// print list, also give column index
void printList(List l);

#endif