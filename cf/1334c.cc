#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n; cin>>n;
	int a[n+1],b[n+1];
	for(int i=0;i<n;i++) cin>>a[i]>>b[i];
	a[n]=a[0]; b[n]=b[0];

	int tot=0,mn=INT_MAX;
	for(int i=0;i<n;i++) {
		tot+=max(0LL,a[i+1]-b[i]);
		mn=min(mn,min(a[i+1],b[i]));
	}
	cout << tot+mn << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
