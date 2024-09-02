#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int m, n; cin >> m >> n;
	int dif[n+1] = {0};
	int l, r, k;
	while(m--) {
		cin >> l >> r >> k;
		dif[l] += k;
		dif[r+1] -= k;
	}
	int c = 0, ans = 0;
	for(int i = 0; i < n; i++) {
		c += dif[i];
		ans = max(c, ans);
	}
	cout << ans << endl;
}
