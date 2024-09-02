#include <bits/stdc++.h>
using namespace std;

signed main() {
	int n,m,c,r,k; cin>>n>>m>>c>>r>>k;
	set<int> vis[n+1];
	vector<pair<int,int>> g[n+1];
	for(int i=0;i<m;i++) {
		int t1,t2,t3;cin>>t1>>t2>>t3;
		g[t1].push_back({t2,t3});
		g[t2].push_back({t1,t3});
	}

 	priority_queue<array<int,3>>q;
	for(int i=1;i<=c;i++) q.push({r,i,i});
	while(!q.empty()) {
		array<int,3> curr=q.top(); q.pop();
		if(vis[curr[1]].size()>=k || vis[curr[1]].count(curr[2])
				|| curr[0]<0) continue;
		vis[curr[1]].insert(curr[2]);

		for(auto i : g[curr[1]]) {
			if(i.second <= curr[0])
				q.push({curr[0]-i.second,i.first,curr[2]});
		}
	}

	vector<int> ans;
	for(int i=c+1;i<=n;i++) {
		if(vis[i].size()>=k) ans.push_back(i);
	}
	cout << ans.size() << endl;
	for(int i : ans) cout << i << endl;
}
