#include <bits/stdc++.h>
using namespace std;

signed main() {
	long long n; cin >> n;
	long long a[n+1];
	a[n] = INT_MAX;
	for(long long i = 0; i < n; i++) cin >> a[i];
	for(long long i = 0; i < n; i++) {
		long long x; cin >> x;
		a[i] -= x;
	}
	sort(a, a+n);

	long long ans = 0;
	for(long long i = 0; i < n; i++) {
		long long l = i+1, r = n;
		while(l < r) {
			long long mid = (l+r)/2;
			if(a[mid]+a[i] <= 0) l=mid+1;
			else r=mid;
		}
		//cout << l << " " << a[l]+a[i] << endl;
		ans += (n-l);
	}
	cout << ans << endl;

	return 0;
}
