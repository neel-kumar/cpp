#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n);
	for(int i = 0; i<m; i++) {
		int a,b; cin >> a >> b;
		g[--a].push_back(--b);
	}

	// dist capital
	int dc[n];
	fill(dc, dc+n, -1);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
	q.push({0,0});
	while(!q.empty()) {
		pair<int,int> t = q.top(); q.pop();
		if(dc[t.second] != -1) continue;
		dc[t.second] = t.first;
		for(int c : g[t.second]) {
			q.push({t.first+1, c});
		}
	}

	// fin trav
	int a[n];
	std::function<void(int, vector<bool>&)> dfs;
	dfs = [&](int x, vector<bool> &u) -> void {
		a[x] = dc[x];
		u[x] = true;
		for(int ch : g[x]) {
			if(dc[ch] > dc[x] && !u[ch])
				dfs(ch,u);
			if(dc[ch] <= dc[x])
				a[x] = min(a[x],dc[ch]);
			else
				a[x] = min(a[x],a[ch]);
		}
    };
	vector<bool> u(n);
	dfs(0, u);
	for(int i=0;i<n;i++) cout << a[i]<<" ";
	cout << endl;
}


signed main() {
	int t; cin >> t;
	while(t--) solve();
}
