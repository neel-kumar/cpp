#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve() {
	int n, m; cin >> n >> m;
	map<int, int> dp;
	vector<vector<int>> seq;
	vector<int> canbe;
	for(int i = 0; i < n; i++) {
		int k; cin >> k;
		vector<int> v(k);
		for(int j = 0; j < k; j++) cin >> v[j];
		sort(v.begin(), v.end());
		seq.push_back(v);

		int c = 0;
		for(int i : v) {
			if(i == c) c++;
		}
		int x = c;
		c++;
		for(int i : v) {
			if(i == c) c++;
		}
		int y = c;
		// x can become y(max)
		dp[x] = max(dp[x], y);
		canbe.push_back(x);
	}

	int cm = 0;
	for(int i = 0; i < canbe.size(); i++) cm = max(cm, canbe[i]);
	vector<int> ans(n);
	int sum = 0;
	for(int i = m; i >= 0; i--) {
		int cur = i;
		while(dp.count(cur) != 0) cur = dp[cur];
		sum += max(cur, cm);
	}
	cout << sum << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
