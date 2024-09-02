#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	if(s[0] == s[n-1]) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
