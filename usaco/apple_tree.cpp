#include <bits/stdc++.h>
using namespace std;

vector<long long> tree[2000010];
long long nleafs[2000010];
long long n, q;

void clear_vars() {
	for(long long i = 1; i <= n; i++) {
		tree[i].clear();
		nleafs[i] = 0;
	}
}

long long dfs(long long node, long long prev) {
	if(nleafs[node]) return nleafs[node];
	if(tree[node].size() == 1 && tree[node][0] == prev) return nleafs[node] = 1;
	for(long long child : tree[node]) if(child != prev) nleafs[node] += dfs(child, node);
	return nleafs[node];
}

signed main() {
	long long t; cin >> t;
	while(t--) {
		cin >> n;
		clear_vars();
		for(long long i = 0; i < n-1; i++) {
			long long a, b; cin >> a >> b;
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
		dfs(1, -1);

		cin >> q;
		for(long long i = 0; i < q; i++) {
			long long a, b; cin >> a >> b;
			cout << nleafs[a]*nleafs[b] << endl;
		}
	}

	return 0;
}
