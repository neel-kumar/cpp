#include <bits/stdc++.h>
using namespace std;

int n,m,t;
vector<int> g[200000];
set<int> dag[200000];
int ind[200000];
int ans = 0;

void dfs(int u) {
	if(ind[u]) return;
	else ans++;

	vector<int> d;
	for(int c : dag[u]) {
		cerr << c+1 << endl;
		assert(ind[c]);
		d.push_back(c);
		ind[c]--;
		dfs(c);
	}
	for(int c : d) dag[u].erase(dag[u].find(c));
}

signed main() {
	cin >> n >> m >> t;
	int ms[m][2];
	for(int i =0; i<m; i++) {
		int a,b; cin >> a >> b;
		a--; b--;
		ms[i][0] = a;
		ms[i][1] = b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	queue<int> q;
	int v[n];
	for(int i=0; i<n; i++) v[i]=-1;
	v[0] = 0;
	q.push(0);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int c : g[u]) {
			if(v[c] == v[u]+1) {
				dag[u].insert(c);
				ind[c]++;
			} else if(v[c] == -1) {
				v[c] = v[u]+1;
				ind[c]++;
				dag[u].insert(c);
				q.push(c);
			}
		}
	}
	for(int i=0; i<n; i++) cerr << v[i] << ' ';
	cerr << endl;

	while(t--) {
		int e; cin >> e;
		e--;
		int a = ms[e][0], b = ms[e][1];
		cerr << a+1 << ' ' << b+1 << endl;
		if(dag[a].count(b) == 0 && dag[b].count(a) == 0) {
			cout << ans << endl;
			continue;
		} else if(dag[a].count(b)) {
			cerr << "KILL: " << b+1 << endl;
			dag[a].erase(dag[a].find(b));
			ind[b]--;
			dfs(b);
		} else {
			cerr << "KILL: " << a+1 << endl;
			dag[b].erase(dag[b].find(a));
			ind[a]--;
			dfs(a);
		}
		cout << ans << endl;
	}

	return 0;
}
