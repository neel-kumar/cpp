#include <bits/stdc++.h>
using namespace std;

int n, m, x;
vector<array<int, 2>> g[100010];

bool check(int cm) {
	deque<array<int, 2>> q;
	q.push_back(array<int,2>({1, 0}));
	bool vis[n+1]; for(int i = 1; i <= n; i++) vis[i] = false;
	while(!q.empty()) {
		auto curr = q.front(); q.pop_front();
		int v = curr[0], d = curr[1];
		if(d >= x) continue;
		if(vis[v]) continue;
		vis[v] = true;
		//cout << v << " " << d << endl;

		for(auto i : g[v]) {
			if(i[1] <= cm) q.push_front(array<int,2>({i[0], d}));
			else q.push_back(array<int,2>({i[0], d+1}));
		}
	}
	return vis[n];
}

void solve() {
	cin >> n >> m >> x;
	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}

	int l = 0, r = 1e9;
	while(l < r) {
		int mid = (l+r)/2;
		if(check(mid)) r = mid;
		else l = mid+1;
	}
	cout << l << endl;
}

signed main() {
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
