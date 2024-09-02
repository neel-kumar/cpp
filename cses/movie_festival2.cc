#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n,k; cin>>n>>k;
	multiset<int> s;
	for(int i=0; i<k; i++) s.insert(INT_MIN);
	vector<pair<int,int>> v(n);
	for(int i=0; i<n; i++) cin>>v[i].second>>v[i].first;
	sort(v.begin(), v.end());

	int ans = 0;
	for(pair<int,int> i : v) {
		auto it = s.upper_bound(i.second);
		if(it != s.begin()) {
			s.erase(
		}
	}
	cout << ans << endl;
}
