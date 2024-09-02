#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

int main() {
	int n, q; cin >> n >> q;
	DSU dsu(n+1);
	array<int, 3> e[n-1];
	for(int i = 0; i < n-1; i++) cin >> e[i][1] >> e[i][2] >> e[i][0];
	sort(e, e+n-1);
	reverse(e, e+n-1);
	array<int, 3> qs[q];
	for(int i = 0; i < q; i++) {
		cin >> qs[i][1] >> qs[i][0];
		qs[i][2] = i;
	}
	sort(qs, qs+q);
	reverse(qs, qs+q);

	int ans[q];
	int ei = 0;
	for(int i = 0; i < q; i++) {
		int x = qs[i][0];
		while(ei < n-1 && e[ei][0] >= x) {
			dsu.unite(e[ei][1], e[ei][2]);
			ei++;
		}
		ans[qs[i][2]] = dsu.size(qs[i][1]);
	}
	for(int i = 0; i < q; i++) cout << ans[i] << " ";
}
