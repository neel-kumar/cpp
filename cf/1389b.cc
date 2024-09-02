#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n,k,z; cin>>n>>k>>z;
	vector<int> a(n);
	int ans=0;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		if(i<=k) ans+=a[i];
	}

	for(int t=1;t<=z;t++) {
		if(t*2 > k) continue;
		int sum=0;
		int mx=0;
		for(int i=0;i<k-(2*t)+1;i++) {
			sum+=a[i];
			if(i < n-1) mx=max(mx,a[i]+a[i+1]);
		}
		ans = max(ans,sum+mx*t);
	}
	cout << ans << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
