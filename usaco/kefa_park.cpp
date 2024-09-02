#include <bits/stdc++.h>
using namespace std;

vector<long long> tree[200010];
long long vis[200010];
bool has_cat[200010];
long long n, m;

long long dfs(long long node, long long prev, long long cats) {
	if(has_cat[node]) cats--;
	if(cats < 0) return 0;
	if(vis[node]) return vis[node];
	if(tree[node].size() == 1 && tree[node][0] == prev) return vis[node] = 1;
	for(long long child : tree[node]) if(child != prev) vis[node] += dfs(child, node, cats);
	return vis[node];
}

signed main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> has_cat[i];
	for(long long i = 0; i < n-1; i++) {
		long long a, b; cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	cout << dfs(1, -1, m) << endl;
	return 0;
}
