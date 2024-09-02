#include <bits/stdc++.h>
#define int long long
using namespace std;

int h,c,t;

long double f(int n) {
	long double x = ( (h+c)/2.0 * (2*n) + h ) / (2.0*n+1.0);
	return abs(t-x);
}

void solve() {
	cin>>h>>c>>t;

	int l=1, r=1e7;
	int ans;
	while(l<=r) {
		int m=(l+r)/2;
		long double x = f(m-1), y = f(m), z = f(m+1);

		if(x > y && y < z) {
			ans = m;
			break;
		} else if(x < y && y < z) {
			r = m-1;
		} else {
			l = m+1;
		}
	}

	if( f(0) <= f(ans) ) {
		cout << 1 << endl;
	} else if( abs(t- (h+c)/2.0) <= f(ans) ) {
		cout << 2 << endl;
	} else {
		cout << 2*ans+1 << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int testcases; cin >> testcases; while(testcases--) solve();
}
