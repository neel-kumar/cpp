#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n, q; cin>>n>>q;
	int p[n+1];
	p[0] = 0;
	for(int i=1; i<=n; i++) {
		int a; cin >> a;
		p[i] = p[i-1]^a;
	}

	while(q--) {
		int l,r; cin>>l>>r;
		cout << (p[r]^p[l-1]) << endl;
	}
}
