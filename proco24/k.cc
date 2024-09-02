#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
	int n, k; cin >> n >> k;
	vector<pair<int,int>> g[n];
	int u, v, w;
	for(int i = 0; i < n; i++) {
		cin >> u >> v >> w;
		u--; v--;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	vector<int> ak(k); for(int i = 0; i < k; i++) cin >> ak[i];

	vector<array<int, 3>> curr;
}
