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

int n;
vector<array<int, 3>> k;

signed main() {
	cin >> n;
	k.resize(n);
	for(int i = 0; i < n; i++) {
		int a=i, b, c; cin >> b >> c;
		k[i] = {b, c, a};
	}

	// adding to dsu
	sort(k.begin(), k.end());
	reverse(k.begin(), k.end());
	DSU dsu = DSU(n);
	set<array<int, 2>> cc;
	for(array<int, 3> i : k) {
		int m = i[1];
		set<array<int, 2>>::reverse_iterator it;
		for (it = cc.rbegin(); it != cc.rend(); it++) {
			array<int, 2> c = *it;
			if(c[0] < i[1]) break;
			m = max(m, c[0]);
			dsu.unite(i[2], c[1]);
		}
		cc.insert({m, i[2]});
	}

	set<int> fin;
	for(int i = 0; i < n; i++) {
		fin.insert(dsu.get(i));
	}
	cout << fin.size();
}
