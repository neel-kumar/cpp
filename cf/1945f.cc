#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n; cin>>n;
	int sh[n], p[n];
	pair<int,int> srt[n];
	for(int i=0; i<n; i++) { cin >> sh[i]; srt[i] = {sh[i], i}; }
	for(int i=0; i<n; i++) { cin >> p[i]; p[i]--; }
	sort(srt, srt+n);
	reverse(srt, srt+n);

	bool used[n] = {0};
	bool notallowed[n] = {0};
	int j = 0, ans = 0, ans2 = 0;
	for(int i=0; i<n && j<n; i++) {
		while(j < n && notallowed[srt[j].second]) j++;
		if(j == n) break;
		if(srt[j].first * (i+1) > ans) {
			ans = srt[j].first * (i+1);
			ans2 = i+1;
		}
		/* cout << j << ' ' << i << ' ' << ans << ' ' << ans2 << endl; */
		used[srt[j].second] = 1; j++;

		notallowed[p[i]] = 1;
		if(used[p[i]]) {
			/* cout << p[i] << endl; */
			used[p[i]] = 0;
			while(j < n && notallowed[srt[j].second]) j++;
			if(j == n) break;
			used[srt[j].second] = 1; j++;
		}
	}
	cout << ans << ' ' << ans2 << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
