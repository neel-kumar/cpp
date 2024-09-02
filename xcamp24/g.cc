#include <bits/stdc++.h>
/* #define int long long */
using namespace std;

signed main() {
	int n,p,k; cin>>n>>p>>k;

	int l = max(p-k,1), r = min(p+k, n);
	if(l != 1) cout << "<< ";
	for(int i = l; i<=r; i++) {
		if(i == p) cout << "(" << p << ") ";
		else cout << i << ' ';
	}
	if(r != n) cout << ">>\n";
	else cout << endl;
}
