#ifndef ADT_H
#define ADT_H

#include <stdbool.h>

typedef struct node *Node;
typedef struct list *List;

typedef struct GraphRep *Graph;

typedef struct Edge {
  Node v;
  Node w;
} Edge;


// function takes x, y coordinate
// return node
Node newNode(int x, int y);
// return empty list
List newList(void);
// given list, free all in list
void freeList(List l);
// add node to the tail of given list
void append(List l, int x, int y);
// print list, also give index
void printList(List l);



#endif