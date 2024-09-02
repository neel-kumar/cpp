#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	if(n == 1) {
		cout << k << endl;
		return;
	}

	int c = k;
	int x = log2(c+1);
	c -= (int)pow(2, x)-1;
	cout << (int)pow(2, x)-1 << " ";
	for(int i = 0; i < n-2; i++) {
		cout << "0 ";
	}
	cout << c << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
