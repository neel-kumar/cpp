#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n; cin>>n;
	set<int> s;
	vector<pair<int,int>> a(n); for(auto &x : a) cin>>x.first>>x.second, s.insert(x.first);
	s.insert(1e9+7);
	sort(a.begin(), a.end());
    priority_queue<int,vector<int>,greater<int>> pq;
	int j=0;
	for(int i=(*s.begin());i<=1e9;) {
		while(j < n && a[j].first <= i) {
			pq.push(a[j].second);
			j++;
		}
		pq.pop();
		if(pq.empty()) i=(*s.lower_bound(i+1));
		else {
			if(pq.top() <= i) break;
			else i++;
		}
	}
	if(!pq.empty()) cout<<"No\n";
	else cout<<"Yes\n";
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
