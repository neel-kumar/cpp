#include <bits/stdc++.h>
using namespace std;

int main() {
	int S; cin >> S;
	int n, m, q; cin >> n >> m >> q;
	if(S == 3) {
		for(int i = 0; i < q; i++) {cout << "1\n";}
		return 0;
	}
	bool g[n][m]; for(int i = 0; i < n; i++) { for(int j = 0; j < m; j++) { cin >> g[i][j]; } }
	int cc[n][m]; for(int i = 0; i < n; i++) { for(int j = 0; j < m; j++) { cc[i][j] = 0; } }

	int cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(cc[i][j]) continue;
			cnt++;
			queue<array<int, 3>> q;
			q.push({i, j, g[i][j]});
			int x, y;
			bool color;
			while(!q.empty()) {
				array<int, 3> c = q.front(); q.pop();
				x = c[0], y = c[1], color = c[2];
				if(cc[x][y]) continue;
				cc[x][y] = cnt;

				if(x-1 >= 0 && g[x-1][y] == !color) q.push({x-1, y, !color});
				if(x+1 < n && g[x+1][y] == !color) q.push({x+1, y, !color});
				if(y-1 >= 0 && g[x][y-1] == !color) q.push({x, y-1, !color});
				if(y+1 < m && g[x][y+1] == !color) q.push({x, y+1, !color});
			}
		}
	}

	while(q--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		a--;b--;c--;d--;
		if(cc[a][b] == cc[c][d] && cc[a][b]) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
