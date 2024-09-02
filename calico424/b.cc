#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int b, l, e; cin >> b >> l >> e;
	b += e;
	l = l-b;
	cout << (int)(b/50) + (int)(l/50) + (l >= 0) << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
