#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);
	int l,n,rf,rb; cin>>l>>n>>rf>>rb;
	int a[n][2]; for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];

	bool wait[n]={0};
	int mx=0;
	for(int i=n-1;i>=0;i--) {
		wait[i] = (a[i][1]>mx);
		mx=max(mx,a[i][1]);
	}

	int ans=0,p=0;
	for(int i=0;i<n;i++) {
		if(wait[i]) {
			int jt=(a[i][0]-p)*rf, bt=(a[i][0]-p)*rb, rt=jt-bt;
			ans += rt*a[i][1];
			p=a[i][0];
		}
	}

	cout << ans << endl;
}
