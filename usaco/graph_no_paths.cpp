#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> in;
int n, m;
bool works = true;
vector<int> g[500001];
int vis[500001];

void dfs(int node, bool color) {
	if(vis[node]) return;
	vis[node] = color+1;
	for(int child : g[node]) {
		if(vis[child] == color+1) works = false;
		if(vis[child]) continue;
		dfs(child, !color);
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x,y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
		in.push_back(make_pair(x, y));
	}

	dfs(1, 0);
	if(!works) cout << "NO\n";
	else {
		cout << "YES\n";
		for(auto i : in) cout << (vis[i.first] == 1);
	}

	return 0;
}
