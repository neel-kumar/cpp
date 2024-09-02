#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1e5+1;
long long n, c1 = 0, c2 = 0;
bool vis[MAXN];
map<long long, vector<long long>> tree;

void dfs(long long node, bool color) {
	vis[node] = 1;
	if(color)
		c1++;
	else
		c2++;
	for(long long i : tree[node]) {
		if(vis[i])
			continue;
		dfs(i, !color);
	}
	return;
}

int main() {
	cin >> n;
	for(long long i = 1; i < n; i++) {
		long long x, y; cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	dfs(1, 0);
	cout << (c1*c2)-n+1 << endl;
	return 0;
}
