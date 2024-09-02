#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, q;
const int N = 4000;
bool g[N][N];
int ps1a[N+1][N+1], v[N+1][N+1], h[N+1][N+1];

signed main() {
	cin >> n >> m >> q;
	char c;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> c;
			g[i][j] = c=='1';
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			ps1a[i][j] = ps1a[i-1][j] + ps1a[i][j-1] - ps1a[i-1][j-1] + g[i-1][j-1];
			//cout << ps1a[i][j] << ' ';
		}
		//cout << endl;
	}
	//cout << endl;
	auto ps1 = [&](int x1, int y1, int x2, int y2) {
		return (ps1a[x2+1][y2+1] - ps1a[x1][y2+1] - ps1a[x2+1][y1] + ps1a[x1][y1]);
	};

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			h[i][j] = h[i-1][j] + h[i][j-1] - h[i-1][j-1];
			if(g[i-1][j-1]) {
				if(j > 1)
					h[i][j] += g[i-1][j-2];
			}
			//cout << h[i][j] << ' ';
		}
		//cout << endl;
	}
		//cout << endl;
	auto hor = [&](int x1, int y1, int x2, int y2) {
		return (h[x2+1][y2+1] - h[x1][y2+1] - h[x2+1][y1+1] + h[x1][y1+1]);
	};

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			v[i][j] = v[i-1][j] + v[i][j-1] - v[i-1][j-1];
			if(g[i-1][j-1]) {
				if(i > 1)
					v[i][j] += g[i-2][j-1];
			}
			//cout << v[i][j] << ' ';
		}
		//cout << endl;
	}
		//cout << endl;
	auto vert = [&](int x1, int y1, int x2, int y2) {
		return (v[x2+1][y2+1] - v[x1+1][y2+1] - v[x2+1][y1] + v[x1+1][y1]);
	};

	while(q--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--; x2--; y2--;
		//cout << ps1(x1, y1, x2, y2) << ' ' << hor(x1, y1, x2, y2) << ' ' << vert(x1, y1, x2, y2) << endl;
		cout << ps1(x1, y1, x2, y2) - hor(x1, y1, x2, y2) - vert(x1, y1, x2, y2) << endl;
	}
}
