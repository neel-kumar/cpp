#include <bits/stdc++.h>
using namespace std;

signed main() {
	int n; cin >> n;
	vector<int> start(n);
	bool adj[n][n];
	for(int i = 0; i < n; i++) cin >> start[i];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			char x; cin >> x;
			adj[i][j] = (x == '1');
		}
	}

	int cnt = 0;
	int vis[n]; for(int i = 0; i < n; i++) vis[i] = 0;
	for(int i = 0; i < n; i++) {
		if(vis[i]) continue;
		cnt++;
		queue<int> q;
		q.push(i);
		while(!q.empty()) {
			auto curr = q.front(); q.pop();
			if(vis[curr]) continue;
			vis[curr] = cnt;
			for(int i = 0; i < n; i++) if(adj[curr][i]) q.push(i);
		}
	}

	vector<int> ans(n);
	for(int num = cnt; num > 0; num--) {
		vector<int> v;
		for(int i = 0; i < n; i++) {
			if(vis[i] == num) v.push_back(i);
		}
		vector<int> vn;
		for(int x : v) vn.push_back(start[x]);
		sort(v.begin(), v.end());
		sort(vn.begin(), vn.end());
		int counter = 0;
		for(int x : v) {
			ans[x] = vn[counter];
			counter++;
		}
	}
	for(int i = 0; i < n; i++) cout << ans[i] << " ";

	return 0;
}
