#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M = 1000000007;
int t;
int dp[1000002][2];

signed main() {
	dp[1][0] = 1; dp[1][1] = 1;
	for(int i = 1; i < (int)(1e6); i++) {
		dp[i+1][0] = (dp[i+1][0]+2*dp[i][0])%M;
		dp[i+1][0] = (dp[i+1][0]+dp[i][1])%M;
		dp[i+1][1] = (dp[i+1][1]+dp[i][0])%M;
		dp[i+1][1] = (dp[i+1][1]+4*dp[i][1])%M;
	}
	cin >> t;
	while(t--) {
		int i; cin >> i;
		cout << (dp[i][0]+dp[i][1])%M << endl;
	}
}
