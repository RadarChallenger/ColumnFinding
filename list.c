#include <stdio.h>
#include <stdlib.h>

#include "list.h"

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

int getNodeID(Node n) {
  return n->nodeID;
}

int getNodeX(Node n) {
  return n->coordinateX;
}

int getNodeY(Node n) {
  return n->coordinateY;
}

int getListSize(List l) {
  return l->size;
}
