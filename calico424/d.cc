#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	bool a[n];
	char c;
	for(int i = 0; i < n; i++) {
		cin >> c;
		a[i] = c=='#';
	}
	if(n <= k) {
		cout << "-1" << endl;
		return;
	}
	priority_queue<int> pq;
	for(int i = 0; i <= k && n-i-1 >= 0; i++) {
		if(a[n-i-1])
			pq.push(n-i-1);
	}

	for(int i = n-k-2; i >= 0; i--) {
		if(!a[i]) continue;
		while(!pq.empty() && pq.top() - i > k+1) {
			pq.pop();
		}
		if(pq.empty()) break;
		pq.pop();
		pq.push(i);
	}

	int ans = 0;
	while(!pq.empty()) {
		ans += pq.top() <= k;
		pq.pop();
	}
	cout << ans << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
