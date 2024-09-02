#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

const int MOD = 1e9+7;

ll binpow(ll a, ll b = MOD - 2){
	int ans = 1;
	for(int i = 1; i<=b; i*=2){
		if(i&b) (ans *= a) %= MOD;
		(a *= a) %= MOD;
	}
	return ans;
}

ll ps[1000001];

void solve() {
	int N; cin>>N;

	int n = ps[N];

	int x = ( binpow(N) * (N-1) ) %MOD;
	cout << (n+MOD-x)%MOD << endl;
}

signed main() {
	int n = 0;
	for(int i=1; i<=1000001; i++) {
		n = (n + binpow(i, MOD-2)) %MOD;
		ps[i] = n;
	}

	int testcases; cin >> testcases; while(testcases--) solve();
}
