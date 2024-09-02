#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
const int MOD = 1e9 + 7;
long long memo[MAXN], n, a, b;

int make_num(int n, int level) {
	if(level == 0 && n != 0) return 0;
	if(memo[n] != 0) return memo[n];
	for(int i = 1; i <= 6; i++) {
		if(n-i >= 0) {
			memo[n] += make_num(n-i, level-1);
			memo[n] %= MOD; // NEEDED????
		}
	}
	return memo[n];
}

double dp[605][605];

signed main() {
	scanf("%lld %lld %lld", &n, &a, &b);
	dp[0][0] = 1.0;
	for (int j = 1; j<=n; j++) {
		for (int i = 1; i < 601; i++) {
			for (int k = 1; k < 7; k++) {
				if (i-k>=0) dp[i][j] += dp[i-k][j-1]*(1.0/6);
			}
		}
	}

	double ans = 0.0;
	for(int i = a; i <= b; i++) { ans += dp[i][n]; }
	printf("%.6f", ans);

	return 0;
}
