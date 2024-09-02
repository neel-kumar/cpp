#include <bits/stdc++.h>
#define int long long
using namespace std;

int log6(int x) {
	while(x >= 6) {
		x /= 6;
	}
	return x;
}

void solve() {
	int n; cin >> n;
	int cnt[5] = {0, 0, 0, 0};
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		int p = log6(x);
		cnt[2] += (p==2 || p==3);
		cnt[4] += (p==4 || p==5);
	}
	if(cnt[2]%2 == 0 && cnt[4]%2 == 0) cout << "Miku" << endl;
	else cout << "Nino" << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
