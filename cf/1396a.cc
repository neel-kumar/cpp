#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n; cin>>n;
	int a[n]; for(int i=0;i<n;i++) cin>>a[i];
	if(n==1) {
		cout << "1 1\n0\n1 1\n0\n1 1\n" << -a[0] << endl;
	} else {
		cout << "1 1\n" << -a[0] << endl;

		cout << "1 " << n << "\n0";
		for(int i=1;i<n;i++) cout << ' ' << -n*a[i];
		cout << endl;

		cout << "2 " << n << "\n";
		for(int i=1;i<n;i++) cout << (n-1)*a[i] << (i<n-1?' ':'\n');
	}
}
