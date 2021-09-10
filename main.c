#include <stdio.h>

#include <ADT.h>

int main() {
  Graph graph = newGraph(5);

  Node col1 = insertVertices(graph, 0, 0);
  Node col2 = insertVertices(graph, 5, 10);
  Node col3 = insertVertices(graph, 2, 8);
  Node col4 = insertVertices(graph, 0, 9);
  Node col5 = insertVertices(graph, 7, 2);

  insertEdge(graph, col1, col2);
  insertEdge(graph, col1, col3);
  insertEdge(graph, col1, col4);
  insertEdge(graph, col2, col4);
  insertEdge(graph, col2, col5);
  insertEdge(graph, col3, col5);

  printGraph(graph);
  return 0;
}