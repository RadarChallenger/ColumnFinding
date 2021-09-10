#ifndef ADT_H
#define ADT_H

#include <stdbool.h>

typedef struct node *Node;
typedef struct list *List;

typedef struct GraphRep *Graph;

// function takes x, y coordinate
// return node
Node newNode(int ID, int x, int y);
// return empty list
List newList(void);
// given list, free all in list
void freeList(List l);
// add node to the tail of given list
void append(List l, Node n);
// print list, also give index
void printList(List l);
// Return size of given list
int getListSize(List l);

Graph newGraph(int numVertices);

Node insertVertices(Graph g, int x, int y);

void insertEdge(Graph g, Node point1, Node point2);

void printGraph(Graph g);


#endif