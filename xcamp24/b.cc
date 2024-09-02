#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n; cin>>n;
	int c[n], p[n];
	for(int i=0; i<n; i++) cin>>c[i]>>p[i];
	int k; cin>>k;
	int r[k];
	multiset<pair<int,int>> tbls;
	for(int i=0; i<k; i++) {
		cin>>r[i];
		tbls.insert({r[i], i+1});
	}

	priority_queue<array<int, 3>> pq;
	for(int i=0; i<n; i++) pq.push({p[i], c[i], i+1});

	int tot = 0;
	vector<pair<int,int>> ans;

	for(int i=0; !pq.empty() && i<k; i++) {
		array<int,3> take = pq.top(); pq.pop();
		while(!pq.empty() && take[1] > (*tbls.rbegin()).first) {
			take = pq.top(); pq.pop();
		}
		if(take[1] > (*tbls.rbegin()).first) break;

		tot += take[0];
		auto it = tbls.lower_bound({take[1], 0});
		if(it == tbls.end()) continue;
		ans.push_back({take[2], (*it).second});
		tbls.erase(it);
	}

	cout << ans.size() << " " << tot << endl;
	for(auto x: ans) cout << x.first << " " << x.second << endl;
}
