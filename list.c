#include <stdio.h>
#include <stdlib.h>

#include "list.h"

typedef struct node {
  int coordinateX;    // Store X coordinate of node
  int coordinateY;    // Store Y coordinate of node
  int nodeID;         // Unique Node ID
  Node next;
} node;

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

  // Loop though list
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }

  free(l);
}

void append(List l, Node n) {
  // if list is empty
  if (l->head == NULL) {
    l->head = n;
    l->tail = n;
    l->size++;
    return;
  }

  // add node to end, change list tail
  l->tail->next = n;
  l->tail = n;
  l->size++;
}

void printList(List l) {
  Node curr = l->head;

  while (curr != NULL) {
    printf("%d,%d --> ", 
      curr->coordinateX, curr->coordinateY);
    curr = curr->next;
  }

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
