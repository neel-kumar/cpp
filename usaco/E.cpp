#include <bits/stdc++.h>
using namespace std;
/* #define int long long */
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

int n,m;
vi a;
set<int> g[200005];
int dp[200005];

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

int dfs(int n) {
	if(dp[n] != -1) return dp[n];

	int r=0;
	for(int i : g[n]) {
		int x=dfs(i);
		if(x!=0) r=max(r,x+1);
	}

	cerr << r << ' ' << n << " trav\n";
	return dp[n]=r;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	a.resize(n);
	DSU dsu(n);
	si tmpg[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i]=-1;
	}
	// trav from N to 1
	for(int i=0; i<m; i++) {
		int u,v; cin >> u >> v;
		u--; v--;
		if(a[u] < a[v])
			tmpg[v].insert(u);
		else if(a[v] < a[u])
			tmpg[u].insert(v);
		else
			dsu.unite(u, v);
	}

	for(int i = 0; i < n; i++) {
		for(int j : tmpg[i])
			g[dsu.get(i)].insert(dsu.get(j));
		print(i, dsu.get(i), g[dsu.get(i)].size(), "DSU");
	}

	dp[dsu.get(0)]=1;
	cout << dfs(dsu.get(n-1)) << endl;
}
