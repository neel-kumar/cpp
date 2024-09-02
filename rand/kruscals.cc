#include <bits/stdc++.h>
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
	// input graph data
	int n, m; cin >> n >> m;
	vector<array<int, 3>> edges(m); // {w, u, v}
	for (int i = 0; i < m; i++) {
		cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
	}

	// kruscals
	sort(edges.begin(), edges.end());
	DSU dsu(n+1);
	vector<array<int, 3>> mst;
	for (auto [w, u, v] : edges) {
		if(!dsu.same_set(u, v)) {
			dsu.unite(u, v);
			mst.push_back({w, u, v});
		}
	}

	// output mst
	for (auto [w, u, v] : mst) {
		cout << u << " " << v << " " << w << endl;
	}
}
