#include <bits/stdc++.h>
using namespace std;

signed main() {
	int t; cin>>t;
	for(int q=0;q<t;q++) {
		int n; cin>>n;
		int c=0,i=1;
		for(;i*i<n;i++) c+=2*!(n%i);
		c += (i*i==n);
		cout<<c<<'\n';
	}
}
