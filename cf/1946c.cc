#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5+1;
int n,k;
vector<int> g[MAXN];
vector<int> sts;

int dfs2(int v, int p) {
	int s=1;
	for(int i : g[v]) {
		if(i!=p) s+=dfs2(i,v);
	}
	sts[v]=s;
	return s;
}

pair<int,int> dfs(int v, int p, int ps, int mid) {
	int sz=sts[v];
	int ret=0;
	for(int u : g[v]) {
		if(u!=p) {
			pair<int,int> x=dfs(u, v, sz-sts[u]+ps, mid);
			sz+=x.first-sts[u];
			ret+=x.second;
		}
	}
	/* cout << v << ' ' << sts[v] << ' ' << sz << ' ' << ret << endl; */
	if(sz>=mid && ps>=mid) return {0,ret+1};
	return {sz,ret};
}

bool check(int mid) {
	pair<int,int> fin = dfs(1, 0, 0, mid);
	/* cout << fin.first << ' ' << fin.second << endl; */
	return (fin.second>=k);
}

void solve() {
	cin >> n >> k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++) {
		int a,b; cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	sts.resize(n+1);
	dfs2(1,0);
	/* for(int i=1;i<=n;i++) cout << sts[i] << ' '; cout << endl; */

	int lo=1, hi=n;
	while(lo<hi) {
		int mid = (lo+hi+1)/2;
		bool wrk=check(mid);
		if(wrk) lo=mid;
		else hi=mid-1;
	}
	cout << lo << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
