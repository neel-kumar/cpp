#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	pair<int, int> a[n];
	for(int i=0; i<n; i++) cin >> a[i].first >> a[i].second;
	sort(a, a + n);
	multiset<int> s;
	for(int i=n-1; i>=0; i--) s.insert(a[i].second);
	s.insert(INT_MIN);
	int ans = INT_MAX;
	set<int> s2;
	for(int i=0; i<n; i++) {
		s.erase(s.find(a[i].second));
		auto it2 = s2.upper_bound(a[i].first), it = it2;
		if(it2 != s2.begin()) it--;
		int x = abs(a[i].first-(*s.rbegin()));
		if(it != s2.end() && (*it) > (*s.rbegin()))
			x = min(x, abs(a[i].first-(*it)));
		if(it2 != s2.end() && (*it2) > (*s.rbegin()))
			x = min(x, abs(a[i].first-(*it2)));
		ans = min(ans, x);
		s2.insert(a[i].second);
	}
	cout << ans << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
