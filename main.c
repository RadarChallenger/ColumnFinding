#include <stdio.h>

#include <ADT.h>

int main() {
  List columns = newList();
  append(columns, 50, 80);
  append(columns, 2, 6);
  append(columns, 9, 67);
  append(columns, 0, 0);
  printList(columns);
  freeList(columns);
  return 0;
}