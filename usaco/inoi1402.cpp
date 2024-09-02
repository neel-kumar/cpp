#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int maxc = 231;
int c, f;
int dist[maxc][maxc];
vector<ii> g[maxc];

void bfs(int source) {
	priority_queue<ii, vector<ii>, greater<ii> > heap; // (dist, vert)
	heap.push(make_pair(0, source));
	while(!heap.empty()) {
		ii curr = heap.top(); heap.pop();
		if(dist[source][curr.second] != -1) continue;
		//cout << source << " " << curr.first << " " << curr.second << endl;
		dist[source][curr.second] = curr.first;
		for(ii child: g[curr.second]) {
			if(dist[source][child.first] == -1) heap.push(make_pair(child.second+curr.first, child.first));
		}
	}
}

signed main() {
	cin >> c >> f;
	for(int i = 0; i < f; i++) {
		int a, b, c; cin >> a >> b >> c;
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}

	for(int i = 0; i < maxc; i++)
		for(int j = 0; j < maxc; j++)
			dist[i][j] = -1;

	for(int i = 1; i <= c; i++) bfs(i);

	int ans = 0;
	for(int i = 1; i <= c; i++) for(int j = 1; j <= c; j++) ans = max(ans, dist[i][j]);
	cout << ans << endl;

	return 0;
}
