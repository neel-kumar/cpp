#include <bits/stdc++.h>
using namespace std;

signed main() {
	int n; cin>>n;
	int a[n+1][2];
	for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];

	int ans=1;
	a[n][0]=INT_MAX;
	for(int i=1;i<n;i++) {
		if(a[i][0]-a[i][1]>a[i-1][0])
			ans++;
		else if(a[i][0]+a[i][1]<a[i+1][0]) {
			a[i][0]+=a[i][1];
			ans++;
		}
	}
	cout << ans << endl;
}
