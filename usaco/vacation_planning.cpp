#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000 // INF, meaning infinity, must be any fairly big number, such as 1B.

int main() {
    ifstream fin("vacation.in");
    ofstream fout("vacation.out");
    int V, E, K, Q, adjMatrix[500][500]; fin >> V >> E >> K >> Q; // adjMatrix meaning: adjacency matrix
    for (int i = 0; i < V; i++) { // init. adjMatrix
        for (int j = 0; j < V; j++)
            adjMatrix[i][j] = INF;
        adjMatrix[i][i] = 0;
        // For example, adjMatrix[2][5] = cost of shortest path from vertex 2 to vertex 5.
        // So adjMatrix[i][i] = cost of shortest path from i to i, which is obviously zero.
    }
    for (int i = 0; i < E; i++) {
        int u, v, w; fin >> u >> v >> w; // u = vertex 1, v = vertex 2, and w = weight.
        u--, v--;
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
                    adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];

    /*cout << endl;
      for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++)
      cout << adjMatrix[i][j] << " ";
      cout << endl;
      } cout << endl;*/

    long long count = 0, cost = 0;
    for(int i = 0; i < Q; i++) {
        int m = INF, a, b; fin >> a >> b; a--, b--;
        for (int j = 0; j < K; j++)
            m = min(m, adjMatrix[a][j] + adjMatrix[j][b]);
        /*
           for(int j = 1; j <= K; j++) {
           int x = adjMatrix[a][j], y = adjMatrix[j][b];
           if(x == INF || y == INF) continue;
           m = min(m, x + y);
           }
           */
        if(m != INF) {
            count++;
            cost += m;
        }
    }
    fout << count << endl;
    fout << cost << endl;

    return 0;
}
