#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	int a[n], b[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];

	int offset = 0;
	while(true) {
		bool works = true;
		for(int i = 0; i < n-offset; i++) {
			if(a[i] > b[i+offset]) {
				works = false;
				break;
			}
		}
		if(works) break;
		else offset++;
	}
	cout << offset << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
