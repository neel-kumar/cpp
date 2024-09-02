#include <bits/stdc++.h>
using namespace std;

#define memeset memset

const int M = (int)1e9+7;

signed main() {
	int n; cin >> n;
	int dp[n+1], p[n+1];
	memeset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; i++) cin >> p[i];

	dp[1] = 2;
	for(int i = 2; i <= n; i++) {
		dp[i] = 2;
		for(int j = p[i-1]; j < i; j++) {
			dp[i] = (dp[i]+dp[j])%M;
		}
	}
	int a = 0; for(int i = 1; i <= n; i++) a = (a+dp[i])%M;
	cout << a << endl;
}
