#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,k;
vector<int> g[200001];
multiset<int> s;

int dfs(int v, int p, int h) {
	int ret=0;
	for(int u : g[v]) {
		if(u!=p) ret+=dfs(u,v,h+1);
	}

	s.insert(ret-h);
	return ret+1;
}

signed main() {
	cin>>n>>k;
	for(int i=1;i<n;i++) {
		int a,b; cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1,-1,0);
	int ans=0;
	for(int i=0;i<n-k;i++) {
		auto it=s.end(); it--;
		ans += *it;
		s.erase(it);
	}
	cout << ans << endl;
}
