// Dijkstra
// This finds cost of shortest path from a starting (source) vertex to all other vertices of a weighted graph.
// Note: There are less comments in this code. It is recommended that you understand BFS first since it is very similar to BFS.
// This code runs in O((V+E) log(V)).

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000 // INF, meaning infinity, must be any fairly big number, such as 1B.
// However, making INF 2B might cause overflow for int.s.
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
	int V, E; scanf("%d %d", &V, &E);
	vector<vii> adjList(V, vii()); // meaning: adjacency list
	for (int i = 0; i < E; i++) {
		int u, v, w; scanf("%d %d %d", &u, &v, &w); // u = vertex 1, v = vertex 2, and w = weight.
		// In directed graph, w is the cost of the edge from u to v.
		// In undirected graph, w is the cost of the edge between u and v.
		adjList[u].push_back(ii(v, w));
		// adjList[v].push_back(ii(u, w)); // This line makes the graph's edges undirected.
		// Uncomment the line above if you want the edge to be undirected and not directed.
		// Definitions: Directed: u -> v. Undirected: u <-> v.
	}

	int s = 2; // starting vertex (or source)
	vi dist(V, INF); // For example, dist[7] = cost of shortest path from vertex s to vertex 7.
	dist[s] = 0; // So dist[s] = cost of shortest path from s to s, which is obviously zero.
	priority_queue<ii, vii, greater<ii>> pq; // Sorted in increasing distance, this stores all the vertices that must travel.
	pq.push(ii(0, s)); // We must start traveling from the source vertex.

	while (!pq.empty()) {
		ii front = pq.top(); pq.pop(); // greedy: pick shortest unvisited vertex
		int d = front.first, u = front.second;
		if (d > dist[u]) continue;
		for (int j = 0; j < adjList[u].size(); j++) { // For all the vertices that can be reached from vertex u
			int v = adjList[u][j].first; // vertex v = a vertex that is reachable from vertex u
			int w = adjList[u][j].second; // w = cost of the edge from u to v.
			if (dist[v] > dist[u] + w)
				dist[v] = dist[u] + w, // update the new cost of shortest path (from s to v)
				pq.push(ii(dist[v], v)); // plan to check vertex v later by appending it to the end of q
		}
	}

	printf("Below are minimum weights required to travel from vertex %d (source) to other vertices:\n", s);
	for (int i = 0; i < V; i++)
		printf("%d -> %d = %d\n", s, i, dist[i]); // cost of shortest path from vertex s to vertex i
	// If dist[i] is INF, it means that vertex i cannot be reached from vertex s.

	return 0;
}
