#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> g[200010];
vector<int> arr, even, odd;

vector<int> bfs(vector<int> sources) {
	vector<bool> vis(n); for(int i = 0; i < n; i++) vis[i] = false;
	vector<int> dist(n); for(int i = 0; i < n; i++) dist[i] = INT_MAX;
	vector<int> ret(n); for(int i = 0; i < n; i++) ret[i] = INT_MAX;

	queue<int> q;
	for(int s : sources) { q.push(s); dist[s] = 0; }
	while(!q.empty()) {
		int pos = q.front(); q.pop();
		if(vis[pos]) continue;
		if(arr[pos]%2 != arr[sources[0]]%2) ret[pos] = min(ret[pos], dist[pos]);
		vis[pos] = true;
		for(int child : g[pos]) {
			q.push(child);
			dist[child] = min(dist[pos]+1, dist[child]);
		}
	}

	return ret;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		//if(i-x >= 0) g[i].push_back(i-x);
		//if(i+x < n) g[i].push_back(i+x);
		if(i-x >= 0) g[i-x].push_back(i);
		if(i+x < n) g[i+x].push_back(i);
		arr.push_back(x);
		if(x%2) even.push_back(i);
		else odd.push_back(i);
	}

	vector<int> dist_odd = bfs(even);
	vector<int> dist_even = bfs(odd);
	int ans[n];
	for(int i : even) { if(dist_even[i] == INT_MAX) ans[i] = -1; else ans[i] = dist_even[i]; }
	for(int i : odd) { if(dist_odd[i] == INT_MAX) ans[i] = -1; else ans[i] = dist_odd[i]; }
	for(int i = 0; i < n; i++) cout << ans[i] << " ";

	return 0;
}
