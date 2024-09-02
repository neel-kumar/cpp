#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 +7;

signed main() {
	int n, m; cin >> n >> m;
	bool adj[n][n]; for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) adj[i][j] = 0;
	int dp[1<<n+1][n]; for(int i = 0; i < (1<<n); i++) for(int j = 0; j < n; j++) dp[i][j] = 0;

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a][b] = 1;
	}

	int all = (1<<n)-1;
	dp[1][0] = 1;
	for(int S = 0; S < (1 << n); S++) {
		for(int i = 0; i < n; i++) {
			if(S & (1 << i)) {
				for(int j = 0; j < n; j++) {
					if((S & (1<<j)) == 0 && adj[i][j]) {
						dp[S^(1<<j)][j] = (dp[S^(1<<j)][j]+dp[S][i]) %mod;
					}
				}
			}
		}
	}

	cout << dp[all][n-1] << endl;

	return 0;
}
