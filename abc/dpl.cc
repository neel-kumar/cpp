#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n; cin>>n;
	int a[n]; for(int i=0;i<n;i++) cin>>a[i];

	int dp[n][n];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j]=INT_MIN;
	for(int i=0;i<n;i++) dp[i][i] = a[i];

	for(int i=1;i<n;i++) {
		for(int l=0,r=i; r<n; l++,r++) {
			dp[l][r] = max(a[l]-dp[l+1][r], a[r]-dp[l][r-1]);
		}
	}

	cout << dp[0][n-1] << endl;
}
