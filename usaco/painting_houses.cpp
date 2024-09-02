#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, s; cin >> n >> m >> s;
	vector<pair<int, int>> twos, ones;
	int g[n+1]; for(int i = 0; i <= n; i++) g[i] = false;
	for(int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		if(c == 1) ones.push_back(make_pair(a, b));
		else twos.push_back(make_pair(a, b));
	}
	int ps[n+1]; for(int i = 0; i <= n; i++) ps[i] = 0;

	for(pair<int, int> range : ones) {
		if(range.first == range.second) continue;
		ps[range.first]++;
		ps[range.second]--;
	}
	for(int i = 1; i <= n; i++) ps[i] = ps[i-1] + ps[i];
	// make comps
	int cnt = 1;
	for(int i = 1; i <= n; i++) {
		if(g[i]) continue;
		g[i] = cnt;
		for(int j = i; ps[j] >= 1 && j < n; j++) g[j+1] = cnt;
		cnt++;
	}

	//for(int i = 1; i <= n; i++) cout << ps[i] << endl;
	//for(int i = 1; i <= n; i++) cout << g[i] << endl;
	for(pair<int, int> range : twos) {
		if(g[range.first] == g[range.second]) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n"; if(s == 0) return 0;
	bool prev = true;
	cout << "A";
	for(int i = 1; i < n; i++) {
		if(ps[i] == 0) prev = !prev;
		if(prev) cout << "A";
		else cout << "B";
	}
	return 0;
}
