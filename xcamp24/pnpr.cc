#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

const int MOD = 1e9+7;

ll binpow(ll a, ll b = MOD - 2){
	ll ans = 1;
	for(int i = 1; i<=b; i*=2){
		if(i&b) (ans *= a) %= MOD;
		(a *= a) %= MOD;
	}
	return ans;
}

void solve() {
	int N,M; cin>>N>>M;
	int n = min(N,M), m = max(N,M);

	int ans = 1;
	for(int i=2; i<=n+m; i++) {
		ans = (ans * binpow(i+1, (min(n, i-1)-max(i-m, 1LL)+1))%MOD)%MOD;
	}

	cout << ans%MOD << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
