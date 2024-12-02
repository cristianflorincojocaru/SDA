#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdio.h>
#include <stdlib.h>

// Structură pentru o muchie a grafului
typedef struct {
    int source;      // Nodul sursă
    int destination; // Nodul destinație
    int weight;      // Costul muchiei
} edge;

// Structură pentru graf
typedef struct {
    int noOfVertices; // Numărul de noduri
    int noOfEdges;    // Numărul de muchii
    edge* pEdge;      // Vector de muchii
} graph;

// Prototipuri pentru funcții
graph* createGraph(int noOfVertices, int noOfEdges);
graph* loadGraph(FILE* f);
void freeGraph(graph* G);

#endif
