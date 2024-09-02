#include <bits/stdc++.h>
using namespace std;

int sbn(int n) {
    int k = __builtin_clz(n);
    return 31 - k;
}

void solve() {
	int n; cin>>n;
	int a[n]; for(int i=0;i<n;i++) cin>>a[i];

	int ans=-1;
	for(int i=1;i<n;i++) {
		int d=a[i]-a[i-1];
		if(d>=0) continue;
		else d=-d;
		/* cout << d << ' ' << sbn(d) << endl; */
		ans = max(ans,sbn(d));
		a[i]=a[i-1];
	}
	cout << ans+1 << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
