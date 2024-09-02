#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;
int dp[1000001];
int n, x;
int c[100];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n >> x;
    for(int i = 0; i < n; i++) {
		cin >> c[i];
    }
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int j = 0; j < n; j++) {
		for(int i = 0; i < x; i++) {
			if(i+c[j] <= x) {
				dp[i+c[j]] = (dp[i+c[j]]+dp[i])%M;
			}
		}
	}
	cout << dp[x] << endl;

    return 0;
}
