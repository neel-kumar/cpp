#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+7;

signed main() {
	int n,k; cin>>n>>k;
	int a[n]; for(int i=0;i<n;i++) cin>>a[i];

	int dp[n+1][k+1];
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<=a[0];i++) dp[0][i] = 1;

	for(int i=0;i<n-1;i++) {
		int c = 0;
		vector<int> ps;
		ps.push_back(0);
		for(int j=0;j<=k;j++) {
			c = (c+dp[i][j]) % MOD;
			ps.push_back(c);
			dp[i+1][j] = (ps[j+1] + MOD - ps[max(0LL, j-a[i+1])]) %MOD;
		}
	}

	cout << dp[n-1][k]%MOD << endl;
}
