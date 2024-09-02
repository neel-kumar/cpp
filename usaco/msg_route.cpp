// Breadth First Search (BFS)
// This finds cost of shortest path from a starting (source) vertex to all other vertices in an unweighted graph.
// This code runs in O(V+E).

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000 // INF, meaning infinity, must be any fairly big number, such as 1B.
// However, making INF 2B might cause overflow for int.s.
typedef vector<int> vi;

vi p; // meaning: parent
int s = 0; // starting vertex (or source)

void printPath(int u) {
	if (u == s) { printf("%d", u+1); return; }
	printPath(p[u]);
	printf(" %d", u+1);
}

int main() {
	int V, E; scanf("%d %d", &V, &E);
	vector<vi> adjList(V, vi()); // meaning: adjacency list
	for (int i = 0; i < E; i++) {
		int u, v; scanf("%d %d", &u, &v); // u = vertex 1 and v = vertex 2
        u--;
        v--;
		adjList[u].push_back(v);
		adjList[v].push_back(u); // This line makes the graph's edges undirected.
		// Omit the line above if you want the edge to be directed and not undirected.
		// Definitions: Directed: u -> v. Undirected: u <-> v.
	}

	vi dist(V, INF); // For example, dist[7] = cost of shortest path from vertex s to vertex 7.
	dist[s] = 0; // So dist[s] = cost of shortest path from s to s, which is obviously zero.
	queue<int> q; // In right order, this stores all the vertices that must travel.
	q.push(s); // We must start traveling from the source vertex.
	p.assign(V, -1); // init. p (to be able to print shortest paths)
	int layer = -1; // for our output printing purpose
	bool isBipartite = true; // addition of one boolean flag, initially true

	while (!q.empty()) { // This means: while (true) until there are no more vertices to check.
		int u = q.front(); q.pop(); // u is a vertex we must travel from
		layer = dist[u];
		for (int j = 0; j < adjList[u].size(); j++) { // For all the vertices that can be reached from vertex u
			int v = adjList[u][j]; // vertex v = a vertex that is reachable from vertex u
			if (dist[v] == INF) // if a new cost of shortest path (from s to v) is found
				dist[v] = dist[u] + 1, // update the new cost of shortest path (from s to v)
				q.push(v), // plan to check vertex v later by appending it to the end of q
				p[v] = u; // store u to p[v] for shortest paths
			else if ((dist[u] % 2) == (dist[v] % 2)) // same parity
				isBipartite = false;
		}
	}

    if(dist[V-1] == INF)
        cout << "IMPOSSIBLE\n";
    else {
        cout << dist[V-1]+1 << endl;
	    printPath(V-1); // prints shortest path from vertex 5 (or source) to vertex 3 in correct order
    }

	return 0;
}
