#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+7;

signed main() {
	int n; cin>>n;
	bool a[n][n];
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++)
			cin>>a[i][j];
	}

	int dp[1<<n];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i=0; i < (1<<n); i++) {
		int sb = __builtin_popcount(i);
		for(int j=0; j<n; j++) if(a[sb][j] && !(i & (1<<j))) {
			dp[i | (1<<j)] = (dp[i] + dp[i | (1<<j)]) %MOD;
		}
	}
	cout << dp[(1<<n)-1] << endl;
}
