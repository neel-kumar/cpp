#include <bits/stdc++.h>
#define int long long
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

void solve() {
	int n,m; cin>>n>>m;
	int a[n]; for(int i=0; i<n; i++) cin>>a[i];
	vector<array<int,3>> edges;
	for(int i=0; i<m; i++) {
		int x,y; cin>>x>>y;
		edges.push_back({max(a[x], a[y]), x, y});
	}

	sort(edges.begin(), edges.end());

	int q; cin >> q;
	vector<array<int,4>> qs(q);
	int j = 0;
	for(auto &i : qs) {
		cin>>i[1]>>i[2]>>i[0];
		i[3] = j++;
	}
	sort(qs.begin(), qs.end());

	int ei = 0;
	DSU dsu(n+1);
	j = 0;
	bool ans[q];
	for(auto i : qs) {
		while(edges[ei][0] <= i[0]) {
			cout << edges[ei][1] << ' ' << edges[ei][2] << endl;
			dsu.unite(edges[ei][1], edges[ei][2]);
			ei++;
		}
		cout << i[3] << endl;
		ans[i[3]] = dsu.same_set(i[1], i[2]);
	}

	for(int i = 0; i < q; i++) cout << (ans[i]?"NO\n":"YES\n");
	cout << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
