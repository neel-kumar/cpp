#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+7;

signed main() {
	int n; cin>>n;
	if(n == 1) {
		cout << "2\n";
		return 0;
	}
	vector<int> g[n+1];
	for(int i=1; i<n; i++) {
		int a,b; cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<int> v;
	queue<pair<int,int>> q;
	q.push({1, -1});
	while(!q.empty()) {
		pair<int,int> p = q.front(); q.pop();
		v.push_back(p.first);
		for(int c : g[p.first]) if(c != p.second) {
			q.push({c, p.first});
		}
	}
	reverse(v.begin(), v.end());

	int dp[n+1][2];
	memset(dp, 0, sizeof(dp));
	set<int> s;
	for(int i : v) {
		s.insert(i);
		dp[i][0] = 1;
		dp[i][1] = 1;
		if(g[i].size() > 1 || s.count(g[i][0])) {
			for(int j : g[i]) {
				if(s.count(j) == 0) continue;
				dp[i][0] = (dp[i][0]*(dp[j][0]+dp[j][1])) %MOD;
				dp[i][1] = (dp[i][1]*dp[j][0]) %MOD;
			}
		}
	}
	cout << (dp[v[n-1]][0]+dp[v[n-1]][1])%MOD << endl;
}
