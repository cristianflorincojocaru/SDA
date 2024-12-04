#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;

// numarul de varfuri (noduri) din graful dat
#define V 6

/* Intoarce true daca exista o cale de la sursa 's' la destinatie
't' in graful rezidual. De asemenea, umple parent[] pentru a stoca
calea */
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
	// Creeaza un vector de vizitate si marcheaza toate varfurile ca nevizitate
	bool visited[V];
	memset(visited, 0, sizeof(visited));

	// Creeaza o coada, pune sursa in coada si marcheaza sursa ca vizitata
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	// Bucla standard BFS
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v = 0; v < V; v++) {
			if (visited[v] == false && rGraph[u][v] > 0) {
				// Daca gasim o conexiune catre destinatie, 
				// nu mai are sens sa continuam BFS-ul, trebuie doar 
				// sa setam parintele si putem returna true
				if (v == t) {
					parent[v] = u;
					return true;
				}
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}

	// Nu am ajuns la destinatie in BFS plecand de la sursa, deci 
	// returnam false
	return false;
}

// Intoarce fluxul maxim de la sursa 's' la destinatie 't' in graful dat
int fordFulkerson(int graph[V][V], int s, int t)
{
	int u, v;

	// Creeaza un graf rezidual si umple-l cu capacitatile date in graf
	// initial ca capacitati reziduale in graf
	
	int rGraph[V][V]; // Graf rezidual unde rGraph[i][j]
				// indica capacitatea reziduala a muchiei
				// de la i la j (daca exista o muchie. Daca
				// rGraph[i][j] este 0, atunci nu exista)
				
	for (u = 0; u < V; u++)
		for (v = 0; v < V; v++)
			rGraph[u][v] = graph[u][v];

	int parent[V]; // Acest vector este umplut de BFS pentru a
				// stocheaza calea

	int max_flow = 0; // Initial nu exista flux

	// Augmenteaza fluxul in timp ce exista o cale de la sursa la destinatie
	while (bfs(rGraph, s, t, parent)) {
	    
		// Gaseste capacitatea reziduala minima a muchiilor de-a lungul
		// caii umplute de BFS. Sau putem spune gaseste fluxul maxim
		// pe calea gasita.
		
		int path_flow = INT_MAX;
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}

		// actualizeaza capacitatile reziduale ale muchiilor si
		// ale muchiilor inverse de-a lungul caii
		
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}

		// Adauga fluxul de pe cale la fluxul total
		max_flow += path_flow;
	}

	// Intoarce fluxul total
	return max_flow;
}

// Programul principal pentru a testa functiile de mai sus
int main()
{
    /*
    Graful este reprezentat astfel:

    (0) --16--> (1) --12--> (3) --20--> (5)
     |           |           |           ^
     |13         |10         |9          |
     v           v           v           |
    (2) --14--> (4) --4-->  (5) <-------|
*/
    
	// Sa cream un graf conform exemplului de mai sus
	int graph[V][V]
		= { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
			{ 0, 4, 0, 0, 14, 0 }, { 0, 0, 9, 0, 0, 20 },
			{ 0, 0, 0, 7, 0, 4 }, { 0, 0, 0, 0, 0, 0 } };

	cout << "Fluxul maxim posibil este "
		<< fordFulkerson(graph, 0, 5);

	return 0;
}
