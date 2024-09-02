#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// typedef deque<long long> dll;
typedef vector<ll> dll;

ll n, k, ans = 0;
ll dp[50005][505] = {0};
dll tree[50005];

void dfs(ll n, ll p) {
	for(ll c : tree[n]) {
		if(c == p) continue;
		dfs(c, n);
		for(ll i = 1; i <= k; i++) ans += dp[c][i-1]*dp[n][k-i];
		for(ll i = 1; i <= k; i++) dp[n][i] += dp[c][i-1];
	}
}

signed main() {
	cin >> n >> k;
	dp[0][0] = 1;
	for(ll i = 1; i < n; i++) {
		ll x, y; cin >> x >> y;
		x--; y--;
		tree[x].push_back(y);
		tree[y].push_back(x);
		dp[i][0] = 1;
	}
	dfs(0, 0);
	cout << ans << endl;

	return 0;
}
