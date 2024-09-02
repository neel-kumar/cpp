#include <bits/stdc++.h>
using namespace std;

int n[2], m[2];
vector<int> g[2][1010];
set<int> paths[2];

int main() {
	cin >> n[0] >> n[1] >> m[0] >> m[1];
	for(int i = 0; i < m[0]; i++) { int x, y; cin >> x >> y; g[0][x].push_back(y); }
	for(int i = 0; i < m[1]; i++) { int x, y; cin >> x >> y; g[1][x].push_back(y); }

	// bfs
	queue<array<int, 3>> q;
	q.push({1, true, 0});
	q.push({1, false, 0});
	while(!q.empty()) {
		array<int, 3> curr = q.front(); q.pop();
		if(curr[0] == n[curr[1]]) paths[curr[1]].insert(curr[2]);
		for(int i : g[curr[1]][curr[0]]) q.push({i, curr[1], curr[2]+1});
	}

	int t; cin >> t;
	while(t--) {
		int sum; cin >> sum;
		bool works = 0;
		for(int i : paths[0]) {
			if(paths[1].count(sum-i)) {
				cout << "1\n";
				works = 1;
				break;
			}
		}
		if(!works) cout << "0\n";
	}

	return 0;
}

