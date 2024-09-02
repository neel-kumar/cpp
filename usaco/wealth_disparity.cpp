#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 200000;
int n;
int cash[MAXN];
vector<int> g[MAXN];

// first = min in subtree, second = max ans within that subtree
pair<int, int> dfs(int node) {
	pair<int, int> ret = {INT_MAX, INT_MIN};
	for(int child : g[node]) {
		pair<int, int> cdfs = dfs(child);
		ret.first = min(ret.first, cdfs.first);
		ret.second = max(ret.second, cdfs.second);
	}
	ret.second = max(cash[node]-ret.first, ret.second);
	ret.first = min(ret.first, cash[node]);

	return ret;
}

signed main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> cash[i];
	int hojo = 0;
	for(int i = 0; i < n; i++) {
		int p; cin >> p;
		if(p == -1) hojo = i;
		else g[p-1].push_back(i);
	}

	cout << dfs(hojo).second << endl;
	return 0;
}
