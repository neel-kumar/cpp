#include <bits/stdc++.h>
#define int long long
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;

signed main() {
	int n; cin >> n;
	int a[n], ps[n+1];
	ps[0]=0;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		ps[i+1] = ps[i]+a[i];
	}

	int dp[n][n];
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++)
			dp[i][j]=INF;
		dp[i][i] = 0;
	}

	for(int i=1; i<n; i++) {
		for(int l=0, r=i; r<n; l++, r++) {
			for(int m=l; m<r; m++)
				dp[l][r] = min(dp[l][r], dp[l][m]+dp[m+1][r] + ps[r+1]-ps[l]);
		}
	}
	cout << dp[0][n-1] << endl;
}
