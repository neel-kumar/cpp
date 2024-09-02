#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n; cin >> n;
	int a[n], s = 0;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		s += a[i];
	}

	if(s % 3 != 0) {
		cout << 0 << endl;
		return 0;
	}

	s /= 3;
	int works[n] = {0}, c = a[0];
	works[0] = (a[0] == s);
	for(int i = 1; i < n-2; i++) {
		c += a[i];
		works[i] = works[i-1] + (c == s);
	}
	int ans = 0;
	c = 0;
	for(int i = n-1; i > 1; i--) {
		c += a[i];
		if(c == s) {
			ans += works[i-2];
		}
	}
	cout << ans << endl;
}
