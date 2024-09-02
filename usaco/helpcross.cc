#include <bits/stdc++.h>
using namespace std;

signed main() {
	freopen("helpcross.in", "r", stdin);
	freopen("helpcross.out", "w", stdout);

	int c,n; cin>>c>>n;
	pair<int,int> a[n]; multiset<int> s;
	for(int i=0;i<c;i++) {
		int x; cin>>x;
		s.insert(x);
	}
	for(int i=0;i<n;i++) cin>>a[i].second>>a[i].first;
	sort(a,a+n);

	int ans=0;
	for(int j=0;j<n;j++) {
		pair<int,int> i = a[j];
		auto ch = s.lower_bound(i.second);
		if(ch != s.end() && *ch <= i.first) {
			ans++;
			s.erase(ch);
		}
	}
	cout << ans << endl;
}
