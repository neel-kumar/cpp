#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n; cin >> n;
	double p[n]; for(int i=0;i<n;i++) cin>>p[i];
	double dp[n][n+1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1.0-p[0];
	dp[0][1] = p[0];

	for(int i=0;i<n-1;i++) {
		for(int j=0;j<=i+1;j++) {
			dp[i+1][j] += dp[i][j] * (1-p[i+1]);
			dp[i+1][j+1] += dp[i][j] * (p[i+1]);
		}
	}

	double ans = 0;
	for(int i=(n+1)/2;i<=n;i++) {
		ans += dp[n-1][i];
	}
	cout << setprecision(10) << ans << endl;
}
