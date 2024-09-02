#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+7;

signed main() {
	int n,m; cin>>n>>m;
	bool g[n][m];
	char c;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>c;
			g[i][j] = c=='.';
		}
	}

	int dp[n][m];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(i<n-1 && g[i+1][j]) dp[i+1][j] = (dp[i+1][j]+dp[i][j]) % MOD;
			if(j<m-1 && g[i][j+1]) dp[i][j+1] = (dp[i][j+1]+dp[i][j]) % MOD;
		}
	}

	cout << dp[n-1][m-1] << endl;
}
