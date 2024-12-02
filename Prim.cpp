#include "Prim.h"
#include "Graph.h"

// Găsește muchia cu cel mai mic cost ce conectează un nod nou
int findEdge(int a[50][50], int Q[50], int n) {
    int i, j, min = VMAX; // `min` reprezintă cel mai mic cost, inițial maxim

    for (i = 1; i <= n; i++)
        if (Q[i] != 0 && a[Q[i]][i] < min) { // Dacă nodul `i` este în coadă și costul este minim
            min = a[Q[i]][i]; // Actualizează minimul
            j = i;           // Stochează nodul selectat
        }

    return j; // Returnează nodul ce urmează să fie adăugat în MST
}

// Inițializează matricea de adiacență `a`, vectorul `Q` și vectorul rezultat `H`
void init(int a[50][50], int Q[50], int H[50], int n) {
    for (int i = 0; i < 50; i++) {
        Q[i] = 0;   // Inițializează coada `Q` (nodurile neprocesate)
        H[i] = 0;   // Inițializează arborele MST
        for (int j = 0; j < 50; j++)
            a[i][j] = 0; // Inițializează matricea de adiacență cu 0
    }
}

// Actualizează coada `Q` cu nodurile conectate la arborele MST
void updateQ(int a[50][50], int Q[50], int n, int j) {
    for (int i = 1; i <= n; i++) 
        if (Q[i] != 0 && a[i][Q[i]] > a[i][j]) // Dacă un cost este mai mic decât cel curent
            Q[i] = j; // Actualizează coada cu nodul `j`
}

// Afișează muchiile din arborele de cost minim (MST)
void displayMST(int H[50], int n) {
    printf("\n MST has the followind edges: \n");

    for (int i = 1; i <= n; i++) 
        if (H[i] != 0) // Dacă există o muchie
            printf("[%d <-> %d] \n", H[i], i); // Afișează muchia
}

// Implementarea algoritmului lui Prim
int prim(int a[50][50], int Q[50], int H[50], int &n, int &r, graph *G) {
    int k = 0, ct = 0; // `k` numără muchiile în MST, `ct` calculează costul total
    int x, y, c, i, j;

    n = G->noOfVertices; // Numărul de noduri din graf
    r = 1;               // Nodul de start pentru MST

    init(a, Q, H, n); // Inițializează matricea și vectorii

    // Inițializează matricea de adiacență cu cost maxim
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (i != j)
                a[i][j] = VMAX;

    // Completează matricea de adiacență cu costurile din graful `G`
    for (i = 0; i < G->noOfEdges; i++) {
        x = G->pEdge[i].source;      // Nodul sursă
        y = G->pEdge[i].destination; // Nodul destinație
        c = G->pEdge[i].weight;      // Costul muchiei

        a[x][y] = a[y][x] = c; 
    }

    // Inițializează coada `Q` cu nodul de start
    for (i = 1; i <= n; i++)
        if (i != r)
            Q[i] = r;

    // Algoritmul lui Prim
    while (k < n - 1) { // Repetă până când MST conține toate nodurile
        j = findEdge(a, Q, n); // Găsește muchia cu cost minim
        H[j] = Q[j];           // Adaugă muchia în MST
        ct += a[Q[j]][j];      // Adaugă costul muchiei în costul total
        Q[j] = 0;              // Elimină nodul din coadă
        updateQ(a, Q, n, j);   // Actualizează coada cu noile costuri
        k++;                   // Incrementează numărul de muchii din MST
    }

    return ct; // Returnează costul total al MST
}
