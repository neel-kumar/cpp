#include <bits/stdc++.h>
using namespace std;

int n, m, sX, sY, lft, rght;
bool g[2010][2010];
bool vis[2010][2010];

int main() {
	cin >> n >> m >> sX >> sY >> lft >> rght;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			char x; cin >> x;
			g[i][j] = (x == '*');
		}
	}

	// 01bfs flood fill
	deque<array<int, 4>> q;
	q.push_back({sX-1, sY-1, lft, rght});
	int ans = 0;
	int x, y, a, b;
	while(!q.empty()) {
		array<int, 4> c = q.front(); q.pop_front();
		x = c[0], y = c[1], a = c[2], b = c[3];
		if(a < 0 || b < 0) continue;
		if(x < 0 || y < 0 || x > n-1 || y > m-1) continue;
		if(vis[x][y]) continue;
		if(g[x][y]) continue;
		vis[x][y] = 1; ans++;

		q.push_front({x-1, y, a, b});
		q.push_front({x+1, y, a, b});
		q.push_back({x, y-1, a-1, b});
		q.push_back({x, y+1, a, b-1});
	}

	cout << ans << endl;
	return 0;
}
