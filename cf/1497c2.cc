#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	while(k > 3) {
		cout << "1 ";
		k--;
		n--;
	}

	if(n%2)
		cout << (n/2) << ' ' << (n/2) << " 1\n";
	else if(n%4)
		cout << (n/2)-1 << ' ' << (n/2)-1 << " 2\n";
	else
		cout << (n/2) << ' ' << (n/4) << ' ' << (n/4) << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int testcases; cin >> testcases; while(testcases--) solve();
}
