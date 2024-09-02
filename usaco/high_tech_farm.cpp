#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <array>
using namespace std;

int n, m;
bool dp[500][500][2];
int grid[500][500];
vector<array<int, 3>> g[510][510];

int main() {
	cin >> n >> m;
	if((n+m)%2) {
		cout << "-1\n";
		return 0;
	}
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) { char x; cin >> x; grid[i][j] = (x!='/'); }
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			g[i][j].push_back({i+1, j+1, !grid[i][j]});
			g[i+1][j+1].push_back({i, j, !grid[i][j]});
			g[i][j+1].push_back({i+1, j, grid[i][j]});
			g[i+1][j].push_back({i, j+1, grid[i][j]});
		}
	}

	bool vis[n+1][m+1]; for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) vis[i][j] = false;
	deque<array<int, 5>> q;
	q.push_back({0, 0, -1, -1, 0});
	while(!q.empty()) {
		auto c = q.front(); q.pop_front();
		int x = c[0], y = c[1];
		if(vis[x][y]) continue;
		vis[x][y] = true;
		if(x == n && y == m) {
			cout << c[4] << endl;
			return 0;
		}
		for(auto i : g[x][y]) {
			if(i[0] == c[2] && i[1] == c[3]) continue;
			if(i[2] == 0) q.push_front({i[0], i[1], x, y, c[4]});
			else q.push_back({i[0], i[1], x, y, c[4]+1});
		}
	}
	cout << "-1\n";

	return 0;
}
