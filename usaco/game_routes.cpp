#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

const int MAX_ADJ = 100001;
const int MAX_MEMO = 300001;
const int mod = 1e9+7;

ll n, m;
vi adj[MAX_ADJ];
ll memo[MAX_MEMO];

// dp[v] = num paths from v to n
ll dp(ll v) {
	assert(v < MAX_ADJ);
	assert(v < MAX_MEMO);
	if(memo[v] != -1) return memo[v];
	if(v == n) return 1;
	ll ret = 0;
	for(ll c: adj[v]) ret = (ret+dp(c))%mod;
	memo[v] = ret;
	return ret;
}

signed main() {
	cin >> n >> m;
	memset(memo, -1, sizeof(memo));
	for(ll i = 0; i < m; i++) {
		ll a, b; cin >> a >> b;
		assert(a < MAX_ADJ);
		adj[a].push_back(b);
	}

	cout << dp(1) << endl;
	return 0;
}
