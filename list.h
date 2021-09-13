#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct node *Node;
typedef struct list *List;

/*
* Function: newNode
* -----------------
* Stores Node unique ID given to function
* Store X and y coorinate in Node
* Set next pointer to NULL
* 
* returns: malloc new Node Struct
*/
Node newNode(int ID, int x, int y);

/*
* Function: newList
* -----------------
* set list size to 0
* head and tail pointer to NULL
* 
* returns: malloc new List Struct
*/
List newList(void);

/*
* Function: freeList
* ------------------
* give list, loops though all node and free them
* free list itself
* 
* returns: void
*/
void freeList(List l);

/*
* Function: append
* ----------------
* add given node to given List
* added node is added at the end
* 
* returns: void
*/
void append(List l, Node n);

/*
* Function: printList
* -------------------
* loop though each node is given list
* print it's x and y coordinate
* 
* returns: void
*/
void printList(List l);

/* Utility Functions: Self explanitory*/
int getListSize(List l);
int getNodeID(Node n);
int getNodeX(Node n);
int getNodeY(Node n);
#endif