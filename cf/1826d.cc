#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	int a[n]; for(int i = 0; i < n; i++) cin >> a[i];

	int pm[n], sm[n];
	pm[0] = a[0]; sm[n-1] = a[n-1]-n+1;
	for(int i = 1; i < n; i++) {
		pm[i] = max(pm[i-1], a[i]+i);
		sm[n-i-1] = max(sm[n-i], a[n-i-1]-n+i+1);
	}

	int ans = 0;
	for(int i = 1; i < n-1; i++) {
		ans = max(ans, a[i]+pm[i-1]+sm[i+1]);
	}
	cout << ans << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
