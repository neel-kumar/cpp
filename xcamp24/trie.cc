#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MXN = 1e5+5;
vector<pair<char,int>> g[MXN];
set<pair<int,int>> rme;
map<int,int> vis;
set<int> bn;

void dfs(int v, int p) {
	if(rme.count({p, v}) || vis[v] > 1) return;
	vis[v]++;
	bn.insert(v);
	bn.insert(p);
	rme.insert({p, v});

	for(pair<char,int> u : g[v]) if(u.second != p) {
		dfs(u.second, v);
	}
}

void solve() {
	int n; cin>>n;
	for(int i=1; i<=n; i++) g[i].clear();
	vis.clear();
	rme.clear();
	bn.clear();
	for(int i=0; i<n-1; i++) {
		char c;
		int u, v; cin>>u>>v>>c;
		g[u].push_back({c,v});
		g[v].push_back({c,u});
	}

	vector<pair<int,int>> bade;
	for(int i=1; i<=n; i++) {
		int freq[26]; memset(freq, 0, sizeof(freq));
		for(pair<char,int> j : g[i]) freq[j.first-'a']++;

		char c = '_';
		for(int j=0; j<26; j++) {
			if(freq[j] == 2 && c == '_') c = (char)(j+'a');
			else if(freq[j] >= 2) {
				cout << "0\n";
				return;
			}
		}

		/* cout << i << ' ' << freq[0] << ' ' << c << endl; */
		if(c != '_') bn.insert(i);
		for(pair<char,int> j : g[i]) if(j.first != c && c != '_') {
			bade.push_back(make_pair(i, j.second));
			/* cout << c << ' ' << i << ' ' << j.second << endl; */
		}
	}

	for(pair<int,int> i : bade) dfs(i.second, i.first);

	/* for(int i : bn) cout << i << ' '; */
	/* cout << endl; */
	cout << n-bn.size() << endl;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int testcases; cin >> testcases; while(testcases--) solve();
}
