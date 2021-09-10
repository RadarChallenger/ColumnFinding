#ifndef GRAPH_H
#define GRAPH_H

#include "list.h"

typedef struct GraphRep *Graph;

Graph newGraph(int numVertices);

Node insertVertices(Graph g, int x, int y);

void insertEdge(Graph g, Node point1, Node point2);

void printGraph(Graph g);

#endif