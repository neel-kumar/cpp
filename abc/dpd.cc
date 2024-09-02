#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n,W; cin>>n>>W;
	int w[n], v[n]; for(int i=0; i<n; i++) cin>>w[i]>>v[i];

	int dp[n][W+1];
	for(int i=0; i<n; i++) for(int j=0; j<W+1; j++) dp[i][j] = -1;
	dp[0][0] = 0;
	dp[0][w[0]] = v[0];
	for(int i=0; i<n-1; i++) {
		for(int j=0; j<W+1; j++) if(dp[i][j] != -1) {
			if(j+w[i+1] <= W)
				dp[i+1][j+w[i+1]] = max(dp[i+1][j+w[i+1]], dp[i][j] + v[i+1]);
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
		}
	}

	cout<<*max_element(dp[n-1], dp[n-1]+W+1)<<endl;
}
