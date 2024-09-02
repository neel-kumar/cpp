#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	int n; cin >> n;
	int arr[n], ps[n+1];
	ps[0] = 0;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		ps[i+1] = ps[i]+arr[i];
	}

	int dp[n][n];
	for(int i = 0; i < n; i++) dp[i][i] = arr[i];

	for(int sz = 1; sz < n; sz++) {
		for(int i = 0; i+sz < n; i++) {
			int j = i+sz;
			assert(j < n);
			assert(i < n);
			dp[i][j] = ps[j+1]-ps[i] - min(dp[i+1][j], dp[i][j-1]);
			//cout << i << " " << j << " " << ps[j+1]-ps[i] << " - min " << dp[i+1][j] << " " << dp[i][j-1] << " = " << dp[i][j] << endl;
		}
	}

	cout << dp[0][n-1] << endl;
	return 0;
}
