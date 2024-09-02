#include <bits/stdc++.h>
using namespace std;

signed main() {
	int n, q; cin >> n >> q;
	int tin[n+1], tout[n+1];
	for(int i = 0; i <= n; i++) {
		tin[i] = 0;
		tout[i] = 0;
	}

	stack<int> s;
	int ct = 0;
	for(int i = 0; i < n; i++) {
		int t; cin >> t;
		if(t == 2) {
			tout[s.top()] = ct;
			s.pop();
		} else {
			ct++;
			int x; cin >> x;
			tin[x] = ct;
			s.push(x);
		}
	}
	while(!s.empty()) {
		tout[s.top()] = ct;
		s.pop();
	}

	while(q--) {
		int a, b; cin >> a >> b;
		if(tin[a] == 0 || tin[b] == 0) {
			cout << "0\n";
			continue;
		}
		if(tout[a] >= tin[b] && tout[a] <= tout[b]) cout << min(tout[a]-tin[a], tout[a]-tin[b])+1 << endl;
		else if(tout[b] >= tin[a] && tout[b] <= tout[a]) cout << min(tout[b]-tin[b], tout[b]-tin[a])+1 << endl;
		else cout << "0\n";
	}

	return 0;
}
