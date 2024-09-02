#include <bits/stdc++.h>
/* #define int long long */
using namespace std;

void solve() {
	int n; cin>>n;
	vector<int> a(n);
	vector<map<int,int>> m(n);
	for(int i=0; i<n; i++) {
		cin>>a[i];
		m[i][a[i]] = 1;
	}
	for(int i=1; i<n; i++) {
		for(auto [x,y] : m[i-1]) {
			int ng = __gcd(x, a[i]);
			m[i][ng] = max(m[i][ng], y+1);
		}
	}

	vector<int> ans(n+1);
	for(int i=0; i<n; i++) {
		for(auto [x,y] : m[i])
			ans[y] = max(ans[y], x);
	}

	for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
	cout<<endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
