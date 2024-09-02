#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define vi vector<int>

struct DSU {
	vector<int> e;
	void init(int N) { e = vi(N, -1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return 0;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return 1;
	}
};

signed main() {
	int n, k; cin >> n >> k;
	DSU dsu;
	dsu.init(n+1);
	int a[n+1];
	set<int> s[n+1];
	set<int> f[n+1];
	for(int i = 1; i <= n; i++) {
		a[i] = i;
	}
	for(int i = 0; i < k; i++) {
		int xamonius, yarowski;
		cin >> xamonius >> yarowski;
		s[a[xamonius]].insert(yarowski);
		s[a[yarowski]].insert(xamonius);
		swap(a[xamonius], a[yarowski]);
	}

	for(int i = 1; i <= n; i++) {
		dsu.unite(a[i], i);
	}

	for(int i = 1; i <= n; i++) {
		for(int j : s[i]) f[dsu.get(i)].insert(j);
		f[dsu.get(i)].insert(i);
	}

	for(int i = 1; i <= n; i++) {
		cout << f[dsu.get(i)].size() << endl;
	}
}
