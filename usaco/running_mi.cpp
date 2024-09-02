#include <bits/stdc++.h>
using namespace std;

// [allb - b(0-l)] -r+l
// all-r (set)  +  l-b[0-l] (max)

void solve() {
	int N; cin >> N;
	int A[N]; for(int i=0; i<N; i++) cin >> A[i];
	int ps[N+1];
	int m=INT_MIN;
	int aa=0;
	int ans = INT_MIN;
	for(int i=0; i<N; i++) {
		ps[i] = i-aa;
		cout << i-aa << endl;
		aa += A[i];
		if(i > 1) {
			m = max(m, ps[i-2]);
			ans = max(aa-i + m, ans);
		}
	}
	cout << ans << endl;
}

signed main() {
	int testcase; cin >> testcase;
	while(testcase--) solve();
}
