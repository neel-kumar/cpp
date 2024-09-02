#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 +7;
long long n;
bool adj[50][50];

// long long dp[1<<21];

signed main() {
	cin >> n;
	for(long long i = 0; i < n; i++)
		for(long long j = 0; j < n; j++)
			cin >> adj[i][j];

	// cout << "size of dp: " << sizeof(long long)*(1<<n) << endl;
	long long dp[1<<n];
	for(long long i = 0; i < (1<<n); i++) dp[i] = 0;
	dp[0] = 1;
	for(long long mask = 0; mask < (1 << n)-1; mask++) {
		assert(__builtin_popcount(mask) < n);
		for(long long i = 0; i < n; i++) {
			assert(mask < (1<<n));
			assert(i < n);
			assert((mask^(1<<i)) < (1<<n));
			if((mask & (1<<i)) == 0 && adj[__builtin_popcount(mask)][i]) {
				dp[mask^(1<<i)] = (dp[mask^(1<<i)]+dp[mask]) %mod;
			}
		}
	}
	cout << dp[(1<<n)-1] << endl;

	return 0;
}
