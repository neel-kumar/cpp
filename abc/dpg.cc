#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5+1;
int n,m,in[MAXN],dp[MAXN];
vector<int> g[MAXN];

signed main() {
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		int a,b; cin>>a>>b;
		g[a].push_back(b);
		in[b]++;
	}

	queue<int> q;
	for(int i=1;i<=n;i++) if(in[i] == 0) {
		q.push(i);
		dp[i]=0;
	}
	while(!q.empty()) {
		int v = q.front(); q.pop();
		for(int u : g[v]) {
			in[u]--;
			dp[u] = max(dp[u], dp[v]+1);
			if(in[u] == 0) q.push(u);
		}
	}

	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	cout << ans << endl;
}
