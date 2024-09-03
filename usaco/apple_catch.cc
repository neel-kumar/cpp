#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n; cin>>n;
	vector<array<int, 3>> appls; // t-x, t+x, n
	vector<array<int, 3>> cows; // t-x, t+x, n
	int q,t,x,ni;
	for(int i=0; i<n; i++) {
		cin>>q>>t>>x>>ni;
		if(q == 1) cows.push_back({t-x, t+x, ni});
		else appls.push_back({t-x, t+x, ni});
	}
	sort(appls.begin(), appls.end());
	sort(cows.begin(), cows.end());

	multiset<array<int, 2>> s; // t+x, ni
	int ans = 0, i = 0;
	for(array<int, 3> a : appls) {
		while(i < cows.size() && cows[i][0] <= a[0]) {
			s.insert({cows[i][1], cows[i][2]});
			i++;
		}

		auto it = s.upper_bound({a[1], INT_MAX});
		while(a[2] > 0 && !s.empty() && it != s.begin()) {
			array<int,2> a2 = *(--it);
			s.erase(it);
			if(a2[1] > a[2]) {
				a2[1] -= a[2];
				ans += a[2];
				a[2] = 0;
				s.insert(a2);
			} else {
				ans += a2[1];
				a[2] -= a2[1];
			}
			it = s.upper_bound({a[1], INT_MAX});
		}
	}
	cout << ans << endl;
}
