#include <bits/stdc++.h>
using namespace std;

signed main() {
	// input
	vector<set<int>> ids;
	int n, k; cin >> n >> k;
	for(int i = 0; i < n; i++) {
		set<int> temp;
		int p; cin >> p;
		while(p--) {
			int a; cin >> a;
			temp.insert(a);
		}
		ids.push_back(temp);
	}

	// construct graph
	vector<int> g[n+1]; for(int i = 0; i <= n; i++) g[i].clear();
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			set<int> set1 = ids[i], set2 = ids[j];
			int cnt = 0;
			for(int num : set1) {
				if(set2.count(num)) cnt++;
			}
			if(cnt >= k) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}

	// final traversal
	set<int> vis;
	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int curr = q.front(); q.pop();
		if(vis.count(curr)) continue;
		vis.insert(curr);
		for(int child : g[curr]) q.push(child);
	}
	cout << vis.size() << endl;

	return 0;
}
