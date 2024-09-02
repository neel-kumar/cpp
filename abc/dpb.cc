#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n,k; cin>>n>>k;
	int a[n]; for(int i=0;i<n;i++) cin>>a[i];

	int dp[n]; for(int i=0;i<n;i++) dp[i] = INT_MAX;
	dp[0] = 0;
	for(int i=0;i<n-1;i++) {
		for(int j=1; j<=k && i+j<n; j++)
			dp[i+j] = min(dp[i+j], dp[i]+abs(a[i]-a[i+j]));

	}
	cout << dp[n-1] << endl;
}
