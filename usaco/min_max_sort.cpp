#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

bool check(int x) {
	int l = x+1, r =n-x;
	vector<int> b;
	for(int i = 0; i<n; i++) {
		if(a[i] >= l && a[i] <= r) b.push_back(a[i]);
	}
	for(int i = 1; i<b.size(); i++) {
		if(b[i]-1 != b[i-1]) return false;
	}
	return true;
}

void solve() {
	cin >> n;
	a.clear();
	a.resize(n);
	for(int i = 0; i<n; i++) cin >> a[i];

	int l = 0, r = (n/2);
	while(l < r) {
		int mid = (l+r)/2;
		if(check(mid)) r = mid;
		else l = mid+1;
	}
	cout << l << endl;
}

signed main() {
	int t; cin >> t;
	while(t--) solve();
}
