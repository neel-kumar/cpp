#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
using ld = long double;
#define f first
#define s second
template<typename... Args>
void print(Args... args) {
    ((cerr << args << " "), ...);
    cerr << endl;
}

int n,tc,tm;
vector<int> a;
vector<int> b;
vector<int> c;

bool solve(int t) {
	for(ord i : o) {
		nm = min(nm, (i.t-t*i.c)/(i.m-i.c));
		nc = min(nc, (i.t-t*i.m)/(i.c-i.m));
	}
	print(t, nm, nc, "SOLVE");
	return (nm+nc >= t);
}

void solve() {
	cin >> n >> tc >> tm;
	o.resize(m);
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}

	int l = 0, r = tc+tm-2;
	while(l < r) {
		int mid = (l+r)/2;
		if(solve(mid)) r=mid;
		else l = mid+1;
	}

	cout << l << endl;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
