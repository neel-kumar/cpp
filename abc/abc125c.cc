#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n; cin >> n;
	int a[n], l[n], r[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	l[0] = a[0]; r[n-1] = a[n-1];
	for(int i = 1; i < n; i++) l[i] = gcd(l[i-1], a[i]);
	for(int i = n-2; i >= 0; i--) r[i] = gcd(r[i+1], a[i]);
	int ans = max(l[n-2], r[1]);
	for(int i = 1; i < n-1; i++) {
		ans = max(ans, gcd(l[i-1], r[i+1]));
	}
	cout << ans << endl;
}
