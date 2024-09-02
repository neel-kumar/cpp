#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		n++;
		int ones = 0;
		int temp = n;
		while(temp > 0) {
			ones = (ones*10)+1;
			temp /= 10;
		}

		int ans = 0;
		int tempn = n;
		while(ones > 1) {
			ans += (tempn/ones) * (int)(ones/10);
			tempn = tempn % ones;
			ones /= 10;
		}
		cout << ans << endl;
	}
	return 0;
}
