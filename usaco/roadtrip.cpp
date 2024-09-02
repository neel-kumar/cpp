#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> g[n+1];
	int ms[n+1];
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 1; i <= n; i++) cin >> ms[i];

	// bfs for all connected comps
	bool vis[n+1]; memset(vis, 0, sizeof(vis));
	vector<int> cc;
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		//bfs
		queue<int> q; q.push(i);
		int cnt = 0;
		while(!q.empty()) {
			int curr = q.front(); q.pop();
			if(vis[curr]) continue;
			vis[curr] = 1;
			cnt += ms[curr];
			for(int child : g[curr]) if(!vis[child]) q.push(child);
		}
		cc.push_back(cnt);
	}

	// 2pts
	if(cc.size() < k) { cout << "-1\n"; return; }
	int l = cc.size()-1, r = 0;
	sort(cc.begin(), cc.end());
	int turn = 0;
	int ans = 0;
	while(turn < k) {
		if(turn%2==0) {
			ans += cc[l];
			l--;
		} else {
			ans += cc[r];
			r++;
		}
		turn++;
	}
	cout << ans << endl;
}

signed main() {
	int t; cin >> t;
	while(t--) solve();
}
