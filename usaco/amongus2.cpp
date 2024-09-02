#include <bits/stdc++.h>
using namespace std;

#define ib pair<int, bool>

void solve() {
	int n, q; cin >> n >> q;
	vector<ib> g[n+1]; // b: 0 == 1
	int a, b, c;
	for(int i = 0; i < q; i++) {
		cin >> c >> a >> b;
		g[a].push_back({b, c==1});
		g[b].push_back({a, c==1});
	}

	int M = 0;
	int vis[n+1]; memset(vis, 0, sizeof(vis)); // 0,per,par
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		vis[i] = 1;
		queue<int> q;
		q.push(i);
		int cnt = 0, cnt1 = 0;

		while(!q.empty()) {
			int curr = q.front(); q.pop();
			cnt += vis[curr]==1;
			cnt1 += vis[curr]==2;
			for(ib child : g[curr]) {
				bool nb = vis[curr]-1 ^ child.second;
				assert(nb+1);
				if(vis[child.first] && vis[child.first] != nb+1) { cout << "-1\n"; return; }
				if(vis[child.first]) continue;
				vis[child.first] = nb+1;
				q.push(child.first);
			}
		}
		M += max(cnt, cnt1);
	}
	cout << M << endl;
}

int main() {
	int t; cin >> t;
	while(t--) solve();
}
