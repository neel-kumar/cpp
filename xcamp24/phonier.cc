#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n,m; cin>>n>>m;
	vector<int> a(n), ps(n+1);
	ps[0] = 0;

	for(int i=0; i<n; i++) {
		cin>>a[i];
		ps[i+1] = ps[i] ^ a[i];
	}

	while(m--) {
		int l,r; cin>>l>>r;
		cout<<2*(ps[r] ^ ps[l-1])<<endl;
	}
}
