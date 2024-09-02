#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	int n; cin >> n;
	int q; cin >> q;
	vector<int> a(n+2);
	for(int i = 1; i <= n; i++) cin >> a[i];
	a[0] = 1e9; a[n+1] = 1e9;

	int r[n+1], l[n+1];
	stack<int> s;
	s.push(0);
	for(int i = 1; i <= n; i++) {
		while(a[s.top()] < a[i]) {
			l[s.top()] = i-1;
			s.pop();
		}
		r[i] = s.top()+1;
		s.push(i);
	}
	while(!s.empty()) {
		l[s.top()] = n;
		s.pop();
	}
	// final ps
	int ps[(int)1e6+1] = {0};
	for(int i = 1; i <= n; i++) {
		ps[a[i]] += (i-r[i]+1) * (l[i]-i+1);
	}
	for(int i = 1; i <= (int)1e6; i++) {
		ps[i] += ps[i-1];
	}

	while(q--) {
		int x; cin >> x;
		cout << ps[x] << endl;
	}
}
