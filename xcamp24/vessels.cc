#include <bits/stdc++.h>
#define int long long
using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (x < y) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

signed main() {
	int n; cin>>n;
	int a[n], l[n];
	for(int i=0; i<n; i++) {
		cin>>a[i];
		l[i] = 0;
	}

	DSU dsu = DSU(n+1);
	int q; cin >> q;
	while(q--) {
		int t; cin>>t;
		if(t == 2) {
			int x; cin>>x;
			x--;
			cout << l[x] << endl;
		} else {
			int p, x; cin>>p>>x;
			p--;
			/* cout << p << ' ' << x << " TRAV\n"; */
			int i = dsu.get(p);
			while(i < n && x > 0) {
				/* cout << i << ' ' << x << endl; */
				if(x >= a[i]-l[i]) {
					x -= a[i]-l[i];
					l[i] = a[i];
					dsu.unite(i, i+1);
				} else {
					l[i] += x;
					x=0;
				}
				i = dsu.get(p);
			}
		}
	}
}
