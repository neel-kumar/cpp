#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,c; cin >> n >> c;
	int a[n]; for(int i=0; i<n; i++) cin >> a[i];
	priority_queue<int> q;
	for(int i=0; i<n; i++) {
		q.push(-1*(a[i]+i+1));
	}
	int i;
	for(i = 0; i<n; i++) {
		cerr << q.top() << " ";
		if(q.top()*-1 > c) break;
		c -= q.top()*-1;
		q.pop();
	}
	cout << i << endl;
}

signed main() {
	int t; cin >> t;
	while(t--) solve();
}
