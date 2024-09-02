#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> g[n];
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	// multisource bfs
	bool vis[n]; for(int i = 0; i < n; i++) vis[i] = false;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(vis[i]) continue;

		// bfs
		queue<int> q;
		q.push(i);
		bool is_val = true;
		bool is_cycle = true;
		int num_vis = 0;
		while(!q.empty()) {
			int i = q.front();
			q.pop();
			num_vis++;
			vis[i] = true;
			for(int c : g[i]) {
				if(g[c].size() != 2) is_val = false;
				if(!vis[c]) q.push(c);
				else is_cycle = true;
			}
		}

		ans += (is_val && is_cycle && num_vis > 2);
		//if(is_val) cout << "BALLS " << i << endl;
	}

	cout << ans << endl;
	return 0;
}
