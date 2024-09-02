#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n, m; cin >> n >> m;
	vector<pair<int,int>> g[n];
	for(int i=0; i<m; i++) {
		int u, v, w; cin >> u >> v >> w;
		u--; v--;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	bool vis[n] = {0};
	int par[n] = {-1};
	priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;
	pq.push({0,0,-1}); // distance, node, parent
	while(!pq.empty()) {
		auto [dist, node, parent] = pq.top(); pq.pop();
		if(vis[node]) continue;
		vis[node] = 1;
		par[node] = parent;
		if(node == n-1) break;
		for(auto [u, w] : g[node]) {
			if(!vis[u]) pq.push({dist+w, u, node});
		}
	}

	if(!vis[n-1]) {
		cout << -1 << endl;
	} else {
		vector<int> path;
		for(int i=n-1; i!=-1; i=par[i]) path.push_back(i);
		reverse(path.begin(), path.end());
		for(int i : path) cout << i+1 << " ";
		cout << endl;
	}
}
