#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
vector<int> g[200005];
bool u[200005];

pair<int,int> dfs(int v, int p) {
	pair<int,int> ret = {0, u[v]};
	for(int u : g[v]) if(u != p) {
		pair<int,int> p = dfs(u, v);
		ret.first += p.first;
		ret.second += p.second;
	}
	ret.first += min(2*k-ret.second, ret.second);
	return ret;
}

signed main() {
	#ifndef LJ // g++ -DLJ
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	cin >> n >> k;
	int a,b;
	for(int i=0; i<2*k; i++) {
		cin >> a;
		u[a] = 1;
	}
	for(int i=1; i<n; i++) {
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	cout << dfs(1, -1).first << endl;
}
