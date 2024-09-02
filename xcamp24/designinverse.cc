#include <bits/stdc++.h>
/* #define int long long */
using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	int g[n][n];
	vector<array<int,3>> edges;
	int a,b,c;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>g[i][j];

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(g[i][j] != g[j][i]) {
				cout<<"NO"<<endl;
				return 0;
			}
			if(i!=j) {
				edges.push_back({g[i][j],i,j});
				if(g[i][j] == 0) {
					cout<<"NO"<<endl;
					return 0;
				}
			} else {
				if(g[i][j] != 0) {
					cout<<"NO"<<endl;
					return 0;
				}
			}
		}
	}
	sort(edges.begin(), edges.end());

	vector<pair<int,int>> mst[n];
	DSU dsu(n);
	for(auto [c,a,b] : edges) {
		if(dsu.unite(a,b)) {
			mst[a].push_back({b, c});
			mst[b].push_back({a, c});
		}
	}

	for(int i=0; i<n; i++) {
		// dfs
		queue<pair<int,int>> q;
		q.push({i,0});
		vector<int> vis(n,0);
		vis[i] = 1;
		while(!q.empty()) {
			auto [u,d] = q.front(); q.pop();
			if(g[i][u] != d) {
				cout<<"NO"<<endl;
				return 0;
			}
			for(auto v : mst[u]) {
				if(!vis[v.first]) {
					vis[v.first] = 1;
					q.push({v.first,d+v.second});
				}
			}
		}
	}
	cout<<"YES"<<endl;
}
