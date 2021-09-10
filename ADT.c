#include <stdio.h>
#include <stdlib.h>

#include <ADT.h>

// Node contain coordinate of column
typedef struct node {
  int coordinateX;
  int coordinateY;
  int nodeID;
  Node next;
} node;

// Store List of column nodes
typedef struct list {
  int size;    // size of list
  Node head;   // points to first node
  Node tail;   // point to last node
} list;

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
  Node nodeCopy1 = newNode(point1->nodeID, point1->coordinateX
    , point1->coordinateY);
  Node nodeCopy2 = newNode(point2->nodeID, point2->coordinateX
    , point2->coordinateY);
  append(g->adjList[point1->nodeID], nodeCopy2);
  append(g->adjList[point2->nodeID], nodeCopy1);
  g->numE++;
}

void printGraph(Graph g) {
  for (int i = 0; i < g->currentSize; i++) {
    printList(g->adjList[i]);
    printf(" END\n");
  }
}


Node newNode(int ID, int x, int y) {
  Node n = malloc(sizeof(n));
  if (n == NULL) {
        fprintf(stderr, "Insufficient memory!\n");
        exit(EXIT_FAILURE);
  }

  n->coordinateX = x;
  n->coordinateY = y;
  n->nodeID = ID;
  n->next = NULL;

  return n;
}

List newList(void) {
  List l = malloc(sizeof(l));
  if (l == NULL) {
        fprintf(stderr, "Insufficient memory!\n");
        exit(EXIT_FAILURE);
  }

  l->size = 0;
  l->head = NULL;
  l->tail = NULL;

  return l;
}

void freeList(List l) {
  Node head = l->head;
  Node temp;

  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }

  free(l);
}

void append(List l, Node n) {
  if (l->head == NULL) {
    l->head = n;
    l->tail = n;
    l->size++;
    return;
  }

  l->tail->next = n;
  l->tail = n;
  l->size++;
  return;
}

void printList(List l) {
  Node curr = l->head;

  for (int i = 0; curr != NULL; curr = curr->next) {
    printf("%d,%d --> ", 
      curr->coordinateX, curr->coordinateY);
    i++;
  }

  return;
}

int getListSize(List l) {
  return l->size;
}
