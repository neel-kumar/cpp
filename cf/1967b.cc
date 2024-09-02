#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	vector<bool> a(n);
	for(int i = 0; i < n; i++) {
		char c; cin >> c;
		a[i] = c == 'U';
	}

	int rounds = 0;
	while(!a.empty()) {
		bool u = 0;
		for(int i : a) u |= i;
		if(!u) break;
		else {
			int i;
			for(i = 0; i < a.size(); i++) {
				if(a[i] == u) break;
			}
			a[ (i+1)%a.size() ] = !a[ (i+1)%a.size() ];
			a[ (i-1+a.size())%a.size() ] = !a[ (i-1+a.size())%a.size() ];
			a.erase(a.begin()+i);
		}
		rounds++;
	}
	cout << (rounds%2==1?"YES":"NO") << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
