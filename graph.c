#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "list.h"

typedef struct GraphRep {
  List *adjList;  // Array of lists
  int numV;        // Number of Vertices
  int numE;        // Number of Edges
  int currentSize; // Keeps track of many many vertices has been added
} GraphRep;

Graph newGraph(int numVertices) {
  Graph g = malloc(sizeof(GraphRep));
  if (g == NULL) {
        fprintf(stderr, "Insufficient memory!\n");
        exit(EXIT_FAILURE);
  }

  //int maxEdges = (numVertices * (numVertices - 1)) / 2;
  g->numV = numVertices;
  g->numE = 0;
  g->currentSize = 0;
  g->adjList = malloc(numVertices * sizeof(List));

  for (int i = 0; i < numVertices; i++)
    g->adjList[i] = NULL;

  return g;
}

Node insertVertices(Graph g, int x, int y) {
  int size = g->currentSize;
  g->adjList[size] = newList();
  Node n = newNode(g->currentSize, x, y);
  append(g->adjList[size], n);
  g->currentSize++;
  return n;
}

void insertEdge(Graph g, Node point1, Node point2) {
  Node nodeCopy1 = newNode(getNodeID(point1), getNodeX(point1)
    ,getNodeY(point1));
  Node nodeCopy2 = newNode(getNodeID(point2), getNodeX(point2)
    ,getNodeY(point2));
  append(g->adjList[getNodeID(point1)], nodeCopy2);
  append(g->adjList[getNodeID(point2)], nodeCopy1);
  g->numE++;
}

void printGraph(Graph g) {
  for (int i = 0; i < g->currentSize; i++) {
    printList(g->adjList[i]);
    printf(" END\n");
  }
}