#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n; cin>>n;
	int abc[n][3];
	for(int i=0; i<n; i++) cin>>abc[i][0]>>abc[i][1]>>abc[i][2];
	int dp[n][3] = {0};
	dp[0][0] = abc[0][0];
	dp[0][1] = abc[0][1];
	dp[0][2] = abc[0][2];
	for(int i=0;i<n-1;i++) { // day
		for(int j=0;j<3;j++) { // last taken activity
			for(int k=0;k<3;k++) {
				if(k == j) continue;
				dp[i+1][k] = max(dp[i+1][k], dp[i][j]+abc[i+1][k]);
			}
		}
	}

	int ans = 0;
	for(int i=0;i<3;i++) ans = max(ans, dp[n-1][i]);
	cout << ans << endl;
}
