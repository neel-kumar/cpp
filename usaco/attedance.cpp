#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<array<int, 3>> intervals;

bool check(int rest, int n, int k) {
	int dp[n+1]; for(int i = 0; i <= n; i++) dp[i] = 0;
	dp[0] = intervals[0][2];
	for(int i = 1; i < n; i++) {
		dp[i] = max(intervals[i][2], dp[i-1]);
		int l = 0, r = i-1;
		while(l < r) {
			int mid = (l+r+1)/2;
			//cout << intervals[mid][1] << " " << mid << " " << k << endl;
			if(intervals[mid][1]+rest <= intervals[i][0]) l = mid;
			else r = mid-1;
		}
		if(intervals[l][1]+rest <= intervals[i][0]) dp[i] = max(dp[i], dp[l]+intervals[i][2]);
		//cout << "CURR " << i << " " << intervals[i][0] << " " << dp[i] << endl;
	}
	return (dp[n-1] >= k);
}

signed main () {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	bool k10 = false;
	for(int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c ;
		intervals.push_back({a, b, c});
		if(c >= k) k10 = true;
	}
	if(k10) {
		cout << "1000000000\n";
		return 0;
	}
	sort(intervals.begin(),intervals.end());

	int l = 0, r = 1e9;
	while(l < r) {
		int mid = (l+r+1)/2;
		if(check(mid, n, k)) l = mid;
		else r = mid-1;
	}
	if(check(l, n, k)) cout << l << endl;
	else cout << "-1\n";

	return 0;
}
