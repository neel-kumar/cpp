#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	int a[n]; for(int i = 0; i < n; i++) cin >> a[i];

	if(n < k) {
		cout << n << endl;
	} else {
		map<int, int> cnt;
		for(int i = 0; i < n; i++) cnt[a[i]]++;
		for(int i = 0; i < n; i++) {
			if(cnt[a[i]] >= k) {
				cout << k-1 << endl;
				return;
			}
		}
		cout << n << endl;
	}
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
