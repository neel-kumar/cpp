#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;
int t, m;
string n;
int dp[200001];

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;

	for(int i = 0; i < 9; i++) dp[i] = 2;
	dp[9] = 3;
	for(int i = 10; i <= 200000; i++) {
		dp[i] = (dp[i-9]+dp[i-10]) %mod;
	}

	while(t--) {
		cin >> n >> m;
		int ans = 0;
		for(char d : n) {
			int dig = d-'0';
			if(dig+m < 10) ans++;
			else {
				assert(m-10+dig >= 0);
				assert(m-10+dig <= 200010);
				ans += dp[m-10+dig];
			}
			ans = ans%mod;
		}
		cout << ans << endl;
	}

	return 0;
}
