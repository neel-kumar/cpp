#include <bits/stdc++.h>
using namespace std;

signed main() {
	#ifndef LJ // g++ -DLJ
	freopen("diamond.in", "r", stdin); freopen("diamond.out", "w", stdout);
	#endif
	int n,k; cin >> n >> k;
	int a[n]; for(int i=0; i<n; i++) cin >> a[i];
	sort(a,a+n);
	int ca[n], ps[n+1]; ps[n]=0;
	for(int i=n-1;i>=0;i--) {
		ps[i] = ca[i] = upper_bound(a,a+n,a[i]+k)-a-i;
		if(i < n-1) ps[i] = max(ps[i], ps[i+1]);
	}
	int ans=0;
	for(int i=0;i<n;i++) ans=max(ca[i]+ps[i+ca[i]], ans);
	cout<<ans<<endl;
}
