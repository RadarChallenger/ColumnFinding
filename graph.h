#ifndef GRAPH_H
#define GRAPH_H

#include "list.h"

typedef struct GraphRep *Graph;

/*
* Function: newGraph
* ------------------
* allocate memory for Graph stuct
* allocate memory for List array x number of vertices
*   - set all to NULL
* 
* returns: malloc new graph Struct
*/
Graph newGraph(int numVertices);

/*
* Function: insertVertices
* ------------------------
* create a new node and place it in given graph adjancentcy list
* The current number of verticies in adjacenctcy is used
* as the node unique ID
* 
* returns: returns new node created
*/
Node insertVertices(Graph g, int x, int y);

/*
* Function: insertEdge
* --------------------
* allocate memory for Graph stuct
* allocate memory for List array x number of vertices
*   - set all to NULL
* 
* returns: malloc new graph Struct
*/
void insertEdge(Graph g, Node point1, Node point2);

void printGraph(Graph g);

#endif