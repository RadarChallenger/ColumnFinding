#include <stdio.h>
#include <stdlib.h>

#include <ADT.h>

// Node contain coordinate of column
typedef struct node {
  int coordinateX;
  int coordinateY;
  Node next;
} node;

// Store List of column nodes
typedef struct list {
  int size;    // size of list
  Node head;   // points to first node
  Node tail;   // point to last node
} list;

typedef struct GraphRep {
  Edge **edges;  // Array of lists
  int numV;     // Number of Vertices
  int numE;     // Number of edges
} GraphRep;

Graph newGraph() {
  Graph g = malloc(sizeof(GraphRep));
  if (g == NULL) {
        fprintf(stderr, "Insufficient memory!\n");
        exit(EXIT_FAILURE);
  }

  g->numV = 0;
  g->numE = 0;
  g->n = 0;

  g->edges = NULL;

  return g;
}

bool equalEdge(Edge e1, Edge e2) {
  return ((e1.v == e2.v && e1.w == e2.w) || (e1.v == e2.w && e1.w == e2.v));
}

void insertEgde(Graph g, Edge e) {
  int i = 0;
  while (i < g->numE && equalEdge(e, g->edges[i])) {
    i++;
  }
  if (i == g->numE) {
    g->edges[g.]
  }
}



Node newNode(int x, int y) {
  Node n = malloc(sizeof(n));
  if (n == NULL) {
        fprintf(stderr, "Insufficient memory!\n");
        exit(EXIT_FAILURE);
  }

  n->coordinateX = x;
  n->coordinateY = y;
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

void append(List l, int x, int y) {
  Node n = newNode(x, y);
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

  for (int i = 1; curr != NULL; curr = curr->next) {
    printf("Column No: %d\t x-coordinate: %d\t y-coordinate: %d\n", i, 
      curr->coordinateX, curr->coordinateY);
    i++;
  }

  return;
}
