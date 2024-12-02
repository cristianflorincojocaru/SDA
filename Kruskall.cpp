#include "Kruskall.h"
#include "Graph.h"

// Implementarea algoritmului lui Kruskal
void kruskal(int &n, int &m, int L[20], graph *G) {
//--------------------------------------Pregătire----------------------------------
    int i = 1, j, k = 0, ct = 0; // `k` - numărul de muchii din MST, `ct` - cost total
    int x, y; // Pentru a uni două componente conexe

    n = G->noOfVertices; // Numărul de noduri

    // Sortează muchiile în funcție de cost (bubble sort simplificat)
    for (i = 0; i < m; i++)
        for (j = i + 1; j < m; j++)
            if (G->pEdge[i].weight > G->pEdge[j].weight) { // Compară costurile
                edge aux = G->pEdge[i];      // Schimbă muchiile
                G->pEdge[i] = G->pEdge[j];
                G->pEdge[j] = aux;
            }
//--------------------------------------END----------------------------------------

//-------------------------------------Kruskal------------------------------------
    // Inițializează vectorul de componente conexe (fiecare nod e propria componentă)
    for (int i = 0; i < n; i++)
        L[i] = i;

    printf("\n MST has the followind edges: \n");

    // Parcurge muchiile în ordinea crescătoare a costurilor
    while (k < n - 1) { // Continuă până când MST are `n-1` muchii
        if (L[G->pEdge[i].source] != L[G->pEdge[i].destination]) { // Dacă sursa și destinația sunt în componente diferite
            k++; // Adaugă muchia în MST
            ct = ct + G->pEdge[i].weight; // Adaugă costul muchiei la costul total

            printf("[%d <-> %d]\n", G->pEdge[i].source, G->pEdge[i].destination);

            x = L[G->pEdge[i].destination]; // Componenta conexă a nodului destinație
            y = L[G->pEdge[i].source];      // Componenta conexă a nodului sursă

            // Unește componentele conexe
            for (int j = 0; j < n; j++)
                if (L[j] == x)
                    L[j] = y; // Toate nodurile din componenta `x` sunt mutate în componenta `y`
        }

        i++; // Trece la următoarea muchie
    }

    printf("\n Total cost = %d \n", ct); // Afișează costul total al MST
}
//--------------------------------------------END---------------------------------
v
