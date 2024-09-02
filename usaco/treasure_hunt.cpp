#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a[n+1]; for(int i = 1; i <= n; i++) cin >> a[i];

	int x, y; cin >> x >> y;
	map<int, vector<int>> p, q;
	for(int i = 0; i < x; i++) {
		int num; cin >> num;
		p[num].push_back(i);
	}
	for(int i = 0; i < y; i++) {
		int num; cin >> num;
		q[num].push_back(i);
	}

	// forward
	int dp[n+1];
	dp[0] = -1;
	for(int i = 1; i <= n; i++) {
		dp[i] = dp[i-1];
		if(dp[i-1] == x-1) dp[i]--;
		if(p.count(a[i]) == 0)
			continue;
		int v = a[i];
		if(upper_bound(p[v].begin(), p[v].end(), dp[i]) == p[v].end()) continue;
		int ub = *upper_bound(p[v].begin(), p[v].end(), dp[i]);
		if(dp[i]+1 == ub)
			dp[i] = ub;
	}

	// backward
	int dpa[n+1];
	dpa[0] = -1;
	for(int i = n; i > 0; i--) {
		int j = n-i+1;
		dpa[j] = dpa[j-1];
		if(dpa[j-1] == y-1) dpa[j]--;
		if(q.count(a[i]) == 0)
			continue;
		int v = a[i];
		if(upper_bound(q[v].begin(), q[v].end(), dpa[j]) == q[v].end()) continue;
		int ub = *upper_bound(q[v].begin(), q[v].end(), dpa[j]);
		if(dpa[j]+1 == ub)
			dpa[j] = ub;
	}

	reverse(dpa+1, dpa+n+1);

	int cnt = 0;
	vector<int> ans;
	for(int i = 1; i <= n; i++) {
		if(dpa[i] == y-1 && dp[i] == x-1) {
			cnt++;
			ans.push_back(i);
		}
	}

	cout << cnt << endl;
	for(int i : ans) {
		cout << i << " ";
	}
	cout << '\n';
}
