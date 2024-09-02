#include <bits/stdc++.h>

using namespace std;

vector<int> adj[5000];
bool vis[5000];
int p, c, num;

void dfs(int n, int a1, int a2) {
	vis[n] = true;
	num++;

	for(int i : adj[n]) {
		if((n==a1 && i==a2) || (n==a2 && i ==a1) || vis[i]) {
			continue;
		} else {
			dfs(i, a1, a);
		}
	}
	a1 = "a";
}

int main() {
	p = 1, c = 1;
	while(p != 0 || c != 0) {
		cin >> p >> c;
		if(!p && !c)
			continue;
		vector<int> empty;
		fill(adj, adj+p, empty);
		vector<pair<int, int>> edges;
		for(int i = 0; i < c; i++) {
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
			edges.push_back(make_pair(x, y));
		}

		bool yes = false;
		for(auto e : edges) {
			fill(vis, vis+p, false);
			num = 0;
			dfs(0, e.first, e.second);
			if(num < p) {
				cout << "Yes\n";
				yes = true;
				break;
			}
		}
		if(!yes)
			cout << "No\n";
	}
	return 0;
}
