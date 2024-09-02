#include <bits/stdc++.h>
#define int long long
using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

signed main() {
	int n, m; cin>>n>>m;
	vector<array<int, 3>> v;
	for(int i = 1; i<n; i++) {
		int a,b,c; cin>>a>>b>>c;
		v.push_back({c,a,b});
	}
	sort(v.begin(), v.end());
	vector<pair<int,int>> q(m);
	for(int i=0; i<m; i++) {
		cin>>q[i].first;
		q[i].second = i;
	}
	sort(q.begin(), q.end());

	DSU dsu = DSU(n+1);
	int ans = 0;
	int i = 0;
	int av[m];
	for(pair<int,int> j : q) {
		while(i < n-1 && v[i][0] <= j.first) {
			int g1 = dsu.size(v[i][1]), g2 = dsu.size(v[i][2]);
			ans -= g1*(g1-1) + g2*(g2-1);
			dsu.unite(v[i][1], v[i][2]);
			g1 = dsu.size(v[i][1]);
			ans += g1*(g1-1);
			i++;
		}
		av[j.second] = ans;
	}

	for(int i=0; i<m; i++) cout << (av[i]/2) << ' ';
	cout << endl;
}
