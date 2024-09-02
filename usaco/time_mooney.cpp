#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("time.in", "r", stdin);
	freopen("time.out", "w", stdout);

	int n, m, c; cin >> n >> m >> c;
	vector<int> g[n+1];
	int cc[n+1]; for(int i = 1; i<=n; i++) cin >> cc[i];
	for(int i=0; i<m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
	}

	int dp[1001][n+1];
	for(int i = 0; i < 1001; i++)
		for(int j = 0; j < n+1; j++)
			dp[i][j] = -1;
	dp[0][1] = 0;
	int ans = 0;
	for(int i = 0; i < 1000; i++) {
		for(int j = 1; j <= n; j++) {
			if(dp[i][j] == -1) continue;
			for(int ch : g[j]) {
				dp[i+1][ch] = max(dp[i+1][ch], dp[i][j]+cc[ch]);
			}
		}
		ans = max(ans, dp[i][1]-c*i*i);
	}
	cout << ans << '\n';

}
