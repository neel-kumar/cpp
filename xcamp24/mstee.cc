#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> tree;

// lca
vector<int> tout, tin;
vector<vector<int>> up;
int N, L, timer;

void dfs(int v, int p) {
	tin[v] = ++timer;
	up[v][0] = p;
	for(int i=1; i<=L; i++)
		up[v][i] = up[up[v][i-1]][i-1];

	for(int i : tree[v]) if(i != p) {
		dfs(i, v);
	}
	tout[v] = ++timer;
}

void build(int root) {
	tout.resize(N);
	tin.resize(N);
    L = ceil(log2(N));
    up.assign(N, vector<int>(L + 1));
	timer = 0;
	dfs(root, -1);
}

bool ancestor(int x, int y) { return tin[x] <= tin[y] && tout[x] >= tout[y]; }

int lca(int x, int y) {
	if(ancestor(x,y)) return x;
	else if(ancestor(y,x)) return y;
	int c = x;
	for(int i=L; i>=0; i--) if(!ancestor(up[x][i], y)) {
		x = up[x][i];
	}
	return up[x][0];
}

signed main() {
	int n, m; cin>>n>>m;
	vector<pair<int,int>> g[n];
	int a,b,c;
	for(int i = 0; i < n; i++) {
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
}
