#include <bits/stdc++.h>
using namespace std;

map<int, vector<int> > g;
map<int, int> f;
set<int> vis;

void dfs(int n) {
	if(vis.count(n) || (n < 0 && f[n*-1] == 0) ) return;
	if(n >= 0) {
		vis.insert(n);
		for(int i : g[n]) dfs(i);
		return;
	}

	// - num
	if(f[n*-1] == 1) {
		for(int i : g[n]) dfs(i);
	} else {
		f[n*-1]--;
	}
}

signed main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a; cin >> a;
		g[0].push_back(a);
	}

	int k; cin >> k;

	int nf = -1;
	for(int i = 0; i < k; i++) {
		int l, r; cin >> l >> r;
		f[-1*nf] = l;
		for(int j = 0; j < l; j++) {
			int x; cin >> x;
			g[x].push_back(nf);
		}
		for(int j = 0; j < r; j++) {
			int x; cin >> x;
			g[nf].push_back(x);
		}
		nf--;
	}

	dfs(0);
	cout << vis.size()-1 << endl;
	for(int i : vis) if(i != 0) cout << i << " ";
}
