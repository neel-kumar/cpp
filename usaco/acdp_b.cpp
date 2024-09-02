#include <bits/stdc++.h>
using namespace std;

signed main() {
	int n,k; cin >> n >> k;
	int a[n],dp[n+k];
	for(int i=0;i<n;i++) {
		cin >> a[i];
		dp[i]=INT_MAX;
	}
	dp[0]=0;
	for(int i=0;i<n;i++) {
		for(int j=1;j<=k;j++)
			dp[i+j]=min(dp[i]+abs(a[i+j]-a[i]), dp[i+j]);
	}
	cout << dp[n-1] << endl;
}
