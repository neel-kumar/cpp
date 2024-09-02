#include <bits/stdc++.h>
using namespace std;

#define int long long;

const int M = 1e9+7;

void solve() {
	int k, n; cin >> k >> n;
	if(k == 1){ cout << (n%3?0:1) << endl; return; }

	int dp[n+10]; memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 0; i < n; i++) {
		if(k==3) {
			dp[i+1] = (dp[i+1]+dp[i])%M;
			dp[i+3] = (dp[i+3]+dp[i])%M;
			dp[i+6] = (dp[i+6]+dp[i]*2)%M;
		} else {
			dp[i+2] = (dp[i+2]+dp[i])%M;
			dp[i+3] = (dp[i+3]+dp[i])%M;
		}
	}
	cout << dp[n] << endl;
}

signed main() {
	int t; cin >> t;
	while(t--) solve();
}
