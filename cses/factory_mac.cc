#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n, t; cin >> n >> t;
	int k[n]; for(int i=0; i<n; i++) cin >> k[i];

	int l = 0, r = 1e18;
	while(l < r) {
		int m = (l+r)/2;

		int cnt = 0;
		for(int i=0; i<n && cnt < t; i++) cnt += m/k[i];

		if(cnt >= t) r = m;
		else l = m+1;
	}

	cout << l << endl;
}
