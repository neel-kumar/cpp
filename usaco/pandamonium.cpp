#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> ans;

int dfs (int u, int p, int t) {
	int d = 0;
	ans[u] = t;
	for (int v : g[u]) {
		if (v != p) {
			d += dfs(v, u, t+d);
		}
	}
	return d+1;
}

void solve() {
	int n; cin >> n;
	g.resize(n+1);
	for(int i = 0; i <= n; i++) g[i].clear();
	ans.resize(n+1); ans.clear();
	for(int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	ans[1] = 1;
	for(int v : g[1]) dfs(v, 1, 1);
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << endl;
}

int main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
