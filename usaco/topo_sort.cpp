#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int n, m;

signed main() {
	cin >> n >> m;
	vi ordering;
	int indeg[n];
	memset(indeg, 0, sizeof(indeg));
	vi adj[n];
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		x--; y--;
		adj[x].push_back(y);
		indeg[y]++;
	}
	// CHECK FOR CYCLES

	queue<int> q;
	for(int i = 0; i < n; i++) if(indeg[i] == 0) q.push(i);
	if(q.empty()) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	while(!q.empty()) {
		int n = q.front();
		q.pop();
		ordering.push_back(n);
		for(int v : adj[n]) {
			indeg[v]--;
			if(indeg[v] == 0) q.push(v);
		}
	}
	if((int)ordering.size() != n) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	for(int x : ordering) cout << x+1 << " ";
	return 0;
}
