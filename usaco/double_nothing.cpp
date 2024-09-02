#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> t[100005];
int c;

int dfs(int v, int p) {
	int m = 0;
	for(int u : t[v]) {
		if(u==p) continue;
		int x = dfs(u,v);
		m = max(m,x);
		if(x == 2) c++;
	}
	return m+1;
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) t[i].clear();
	if(n<=2) {
		cout << "NO" << endl;
		return;
	}

	for(int i = 1; i < n; i++) {
		int a,b; cin >> a >> b;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	c = 0;
	dfs(1,0);
	if(c > 2) cout << "NO" << endl;
	else cout << "YES" << endl;
}

signed main() {
	int t; cin >> t;
	while(t--) solve();
}
