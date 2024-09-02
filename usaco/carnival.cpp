#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,p;
int a[100005];

bool check(int t) {
	cerr << "CHECK " << t << endl;
	// a[i]-p*x-u-(t-x)
	// least x where ^ <= 0
	int u = 0; // used so far
			   // upd t to be throws left
	for(int i = 0; i < n; i++) {
		int l=0, r = t-u;
		while(l<r) {
			int mid = (l+r)/2;
			if( (a[i]-(p*mid)-(t-mid)) <= 0) r = mid;
			else l = mid+1;
		}
		if((a[i]-(p*l)-(t-l)) > 0) return false;
		u += l;
		cerr << a[i] << ' ' << u << " " << l << endl;
	}
	return true;
}

signed main() {
	cin >> n >> p;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a,a+n,std::greater<int>());
	int l=0, r = 1e9;
	while(l<r) {
		int mid = (l+r)/2;
		if(check(mid)) r = mid;
		else l = mid+1;
	}
	cout << l << endl;
}
