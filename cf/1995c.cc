#include <bits/stdc++.h>
#define int long long
using namespace std;

pair<int,int> f(int x, int a) {
	int ret = 0;
	while(a < x) {
		a *= a;
		ret++;
	}
	return make_pair(ret, a);
}

void solve() {
	int n; cin>>n;
	int ans = 0, prev = 0;
	for(int i=0; i<n; i++) {
		int x; cin>>x;
		if(x < prev) {
			if(x==1) {
				cout << "-1" << endl;
				return;
			}
			pair<int,int> p = f(prev, x);
			ans += p.first;
			prev = p.second;
		} else {
			prev = x;
		}
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int testcases; cin >> testcases; while(testcases--) solve();
}
