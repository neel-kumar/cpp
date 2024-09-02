#include <bits/stdc++.h>
using namespace std;

long long n, e, x, k;
bool vis[100001][2];
set<long long> ans;
vector<long long> g[100001];

void bfs(long long v, long long hops) {
	queue<array<long long, 2>> q;
	q.push({v, hops});
	while(!q.empty()) {
		auto c = q.front(); q.pop();
		if(c[1]%2 == 0) ans.insert(c[0]);
		if(c[1] == 0) continue;
		if(vis[c[0]][c[1]%2]) continue;
		vis[c[0]][c[1]%2] = true;
		for(auto i : g[c[0]]) q.push({i, c[1]-1});
	}
}

signed main() {
	cin >> n >> e >> x >> k;
	for(long long i = 0; i < e; i++) {
		long long a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	bfs(x, k);
	cout << ans.size();

	return 0;
}
