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

void solve() {
	int lx=INT_MAX,hx=INT_MIN,ly=INT_MAX,hy=INT_MIN;
	for(int i=0;i<4;i++) {
		int x,y; cin>>x>>y;
		lx=min(x,lx);
		hx=max(x,hx);
		ly=min(y,ly);
		hy=max(y,hy);
	}
	cout << (hx-lx)*(hy-ly) << endl;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}
