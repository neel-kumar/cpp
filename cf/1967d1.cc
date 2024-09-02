#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n, m; cin >> n >> m;

	int cnt = 0;
	for(int a = 1; a <= n; a++) {
		for (int i=1; i <= m; i++) {
			if( (a+i) < __gcd(a, i)*i || (a+i) % __gcd(a, i)*i != 0) {
				break;
			}
			if (a%i == 0) {
				cout << a << ' ' << i << endl;
				cnt++;
			}
		}
	}

	cout << cnt << endl << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
