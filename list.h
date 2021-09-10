#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct node *Node;
typedef struct list *List;

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
int getNodeID(Node n);
int getNodeX(Node n);
int getNodeY(Node n);
#endif