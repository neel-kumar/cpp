#include <bits/stdc++.h>

using namespace std;

vector<int> adj[21];
int N, K;
bool vis[21];
bool cycle[21];
vector<int> path;

void count(int node) {
	printf("NODE%d ", node);
	if(path[path.size()-3] == node)
		return;
	cycle[node] = true;
	for(int i = path.size()-1; i >= 0; i--) {
		cycle[path[i]] = true;
	}
}

void dfs(int n) {
	if(vis[n]) {
		count(n);
		return;
	}
	vis[n] = true;

	for(int i : adj[n]) {
		path.push_back(i);
		dfs(i);
		path.pop_back();
	}
}

int main() {
	cin >> N >> K;
	for(int i = 0; i < K; i++) {
		int a, b, sa, sb; cin >> a >> b >> sa >> sb;
		if(sa > sb)
			adj[a].push_back(b);
		else
			adj[b].push_back(a);
	}
	path.push_back(1);
	dfs(1);

	int ans = 0;
	for(int i = 0; i <= N; i++)
		ans += cycle[i];
	cout << ans << endl;

	return 0;
}
