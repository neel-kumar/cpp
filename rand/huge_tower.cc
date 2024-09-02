#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+9;

signed main() {
	int n, d; cin>>n>>d;
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	sort(a, a+n);

	int ans = 1;
	for(int l=0, r=1; r<n; r++) {
		while(a[l]+d <= a[r]) l++;
		ans = ans*(r-l+1) %MOD;
	}
	cout << ans << endl;
}
