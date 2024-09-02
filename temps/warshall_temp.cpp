// Floyd Warshall
// This finds cost of shortest paths between all vertices of a weighted graph.
// This code runs in O(V^3).
// Note: O(V^3) is very slow. V must be less than or around 400 for this code to run in a second.

#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000000 // INF, meaning infinity, must be any fairly big number, such as 1B.
// However, making INF 2B may cause overflow for int when adding: adjMatrix[i][k] + adjMatrix[k][j]

int p[500][500]; // meaning: parent matrix
void printPath(int i, int j) { // prints shortest path in correct order
	if (i != j) printPath(i, p[i][j]);
	printf(" %d", j);
}

int main() {
	int V, E, adjMatrix[500][500]; scanf("%d %d", &V, &E); // adjMatrix meaning: adjacency matrix
	for (int i = 0; i < V; i++) { // init. adjMatrix
		for (int j = 0; j < V; j++)
			adjMatrix[i][j] = INF;
		adjMatrix[i][i] = 0;
		// For example, adjMatrix[2][5] = cost of shortest path from vertex 2 to vertex 5.
		// So adjMatrix[i][i] = cost of shortest path from i to i, which is obviously zero.
	}
	for (int i = 0; i < V; i++) // init. p (to be able to print shortest paths)
		for (int j = 0; j < V; j++)
			p[i][j] = i;

	for (int i = 0; i < E; i++) {
		int u, v, w; scanf("%d %d %d", &u, &v, &w); // u = vertex 1, v = vertex 2, and w = weight.
		// In directed graph, w is the cost of the edge from u to v.
		// In undirected graph, w is the cost of the edge between u and v.
		adjMatrix[u][v] = w;
		// adjMatrix[v][u] = w // This line makes the graph's edges undirected.
		// Uncomment the line above if you want the edge to be undirected and not directed.
		// Definitions: Directed: u -> v. Undirected: u <-> v.
	}

	for (int k = 0; k < V; k++) // common error: remember that loop order is k -> i -> j
		for (int i = 0; i < V; i++) // "i" is "u", meaning vertex 1
			for (int j = 0; j < V; j++) // "j" is "v", meaning vertex 2
				if (adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j])
					adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j],
					p[i][j] = p[k][j]; // store p[k][j] to p[i][j] for shortest paths

	printf("Below are minimum weights required to travel from a vertex to another:\n");
	for (int i = 0; i < V; i++) // "i" is "u", meaning vertex 1
		for (int j = 0; j < V; j++) // "j" is "v", meaning vertex 2
			adjMatrix[i][j] != INF ?
				printf("%d -> %d = %d\n", i, j, adjMatrix[i][j]) :
				printf("%d -> %d cannot be reached.\n", i, j);
				// If adjMatrix[i][j] is INF, it means that vertex j cannot be reached from vertex i.

	printf("\nBelow are shortest paths from a vertex to another:\n");
	for (int i = 0; i < V; i++) // "i" is "u", meaning vertex 1
		for (int j = 0; j < V; j++) // "j" is "v", meaning vertex 2
			adjMatrix[i][j] != INF ?
				printf("%d -> %d:  ", i, j), printPath(i, j), printf("\n") :
				printf("%d -> %d:   cannot be reached.\n", i, j);

	return 0;
}
