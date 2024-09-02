#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
using ld = long double;
using ll = long long;

int m, n, c[100000];

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

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
	cin >> n >> m;
	DSU dsu(n+1);
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		dsu.unite(a, b);
	}

	vector<int> ans;
	for(int i = 1; i <= n; i++) {
		if(dsu.e[i] < 0)
			ans.push_back(i);
	}

	cout << ans.size()-1 << endl;
	for(int i = 0; i < ans.size()-1; i++)
		cout << ans[i] << " " << ans[i+1] << endl;

	return 0;
}
