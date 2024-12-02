#include "Graph.h"

// Creează un nou graf și inițializează structura sa
graph* createGraph(int noOfVertices, int noOfEdges) {
    graph* G = (graph*)malloc(sizeof(graph)); // Alocă memorie pentru graful G

    G->noOfVertices = noOfVertices; // Setează numărul de noduri
    G->noOfEdges = noOfEdges;       // Setează numărul de muchii

    // Alocă memorie pentru vectorul de muchii
    G->pEdge = (edge*)malloc(sizeof(edge) * noOfEdges);

    return G; // Returnează graful creat
}

// Încarcă graful dintr-un fișier
graph* loadGraph(FILE* f) {
    int i, noOfVertices, noOfEdges;
    fscanf(f, "%d", &noOfVertices); // Citește numărul de noduri
    fscanf(f, "%d", &noOfEdges);    // Citește numărul de muchii

    graph* G = createGraph(noOfVertices, noOfEdges); // Creează graful

    // Parcurge fiecare muchie și încarcă datele (sursă, destinație, cost)
    for (i = 0; i < noOfEdges; i++) {
        fscanf(f, "%d%d%d", &G->pEdge[i].source, &G->pEdge[i].destination, &G->pEdge[i].weight);
    }

    return G; // Returnează graful încărcat
}

// Eliberează memoria utilizată de graf
void freeGraph(graph* G) {
    free(G->pEdge); // Eliberează vectorul de muchii
    free(G);        // Eliberează structura grafului
}
