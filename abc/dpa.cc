#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n; cin>>n;
	int a[n]; for(int i=0;i<n;i++) cin>>a[i];

	int dp[n]; for(int i=0;i<n;i++) dp[i] = INT_MAX;
	dp[0] = 0;
	for(int i=0;i<n-1;i++) {
		dp[i+1] = min(dp[i+1], dp[i]+abs(a[i]-a[i+1]));
		dp[i+2] = min(dp[i+2], dp[i]+abs(a[i]-a[i+2]));
	}
	cout << dp[n-1] << endl;
}
