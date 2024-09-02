#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	int a[2*n];
	for(int i=0;i<n*2;i++) cin>>a[i];
	sort(a, a+2*n);
	if(a[0]!=a[1] || a[0]%2==1) {
		cout << "NO\n";
		return;
	}
	vector<int> diff;
	int j=1, x=a[0];
	for(int i=2;i<n*2;i+=2,j++) {
		int d = a[i]-a[i-1];
		if(a[i]!=a[i+1] || d==0 || d%(2*j)) {
			cout << "NO\n";
			return;
		}
		d=d/2/j;
		diff.push_back(d);
		x-=2*(n-j)*d;
	}
	cout << ((x<1 || x%(n*2))?"NO":"YES") << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
