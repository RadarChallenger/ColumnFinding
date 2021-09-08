#include <stdio.h>
#include <stdlib.h>

#include <ADT.h>

// Node contain coordinate of column
struct node {
  int coordinateX;
  int coordinateY;
  Node next;
};

// Store List of column nodes
struct list {
  int size;
  Node head;
  Node tail;
};

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
