#include <bits/stdc++.h>
using namespace std;

long long dp[5000][5000];

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long n; cin >> n;
	long long a[n], b[n], ps[n+1];
	ps[0] = 0;
	for(long long i = 0; i < n; i++) cin >> a[i];
	for(long long i = 0; i < n; i++) cin >> b[i];
	for(long long i = 0; i < n; i++) ps[i+1] = ps[i]+ a[i]*b[i];

	long long ans = ps[n];
	for(long long i = 0; i < n; i++) {
		dp[i][i] = a[i]*b[i];
		if(i != n-1) {
			dp[i][i+1] = a[i+1]*b[i] + a[i]*b[i+1];
			ans = max(ans, dp[i][i+1] +ps[i] +ps[n]-ps[i+2]);
		}
	}
	for(long long i = n-1; i > -1; i--) {
		for(long long j = i+2; j < n; j++) {
			dp[i][j] = a[i]*b[j] + a[j]*b[i] + dp[i+1][j-1];
			//cerr << i << " " << j << " " << dp[i][j] +ps[i] + ps[n]-ps[j+1] << endl;
			ans = max(ans, dp[i][j] +ps[i] + ps[n]-ps[j+1]);
		}
	}
	cout << ans << endl;

	return 0;
}
