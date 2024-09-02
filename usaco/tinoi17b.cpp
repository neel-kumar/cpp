#include <bits/stdc++.h>
using namespace std;

long long dp[5005][5005];

long long main() {
	long long N, S; cin >> N >> S;
	long long E[N]; for(long long i = 0; i < N; i++) cin >> E[i];

	// s[i] = str after training i times
	long long s[N+1]; s[0] = S;
	for(long long i = 1; i <= N; i++) {
		s[i] = 0;
		long long x = s[i-1];
		while(x) { s[i] += x%10; x/=10; }
		s[i] = s[i]*s[i]*s[i] +s[i-1];
	}

	// dp

	dp[0][0] = s[0]*E[0]; dp[0][1] = 0;
	for(long long c = 1; c < N; c++) {
		dp[c][0] = dp[c-1][0]+s[0]*E[c];
		dp[c][c+1] = 0;
		for(long long t = 1; t <= c; t++) {
			dp[c][t] = max(dp[c-1][t]+s[t]*E[c], dp[c-1][t-1]);
		//	prlong longf("C:%d T:%d = %d\n", c, t, dp[c][t]);
		}
	}
	for(long long i = 0; i < N; i++) dp[N-1][i] = s[i]*E[N-1] + dp[N-2][i];

	long long ans = 0; for(long long i = 0; i <= N; i++) ans = max(ans, dp[N-1][i]);
	cout << ans << endl;
}
