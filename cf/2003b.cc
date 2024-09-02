#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	int a[n];
	multiset<int> s;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}

	for(int i = 0; i < n-1; i++) {
		if(i%2 == 0) {
			s.erase(s.begin());
		} else {
			s.erase(--s.end());
		}
	}

	cout << *s.begin() << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
