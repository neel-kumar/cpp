#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<vector<pair<int, int>>> g;
vector<int> p;

struct Compare{
	bool operator()(array<int,3> a,array<int,3> b){
		return a[0]>b[0];
	}
};

int bfs(int r) {
	// heap instead of queue
	// keep previous node
	// pq<array<int, 3>
	priority_queue<array<int, 3>, vector<array<int, 3>>, Compare > q; // dist, node, prev
	q.push({0, r, -1});
	int v[n+1]; memset(v, 0, sizeof(v));

	while(!q.empty()) {
		array<int, 3> c = q.top(); q.pop();
		if(v[c[1]] && v[c[1]] <= c[0]) continue;
		v[c[1]] = c[0];
		for(pair<int, int> child : g[c[1]]) {
			if(child.first == c[2]) continue;
			q.push({c[0]+child.second, child.first, c[1]});
		}
	}

	// final calc
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += (v[i]*p[i]);
	}
	return ans;
}

signed main() {
	cin >> n;
	// 1 indexed
	g.resize(n+1);
	p.resize(n+1);

	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}

	for(int i = 1; i <= n; i++) {
		cout << bfs(i) << " ";
	}
}
