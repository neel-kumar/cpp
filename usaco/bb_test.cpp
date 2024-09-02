#include <bits/stdc++.h>
using namespace std;

signed main() {
	int x,y; cin >> x >> y;
	int n; cin >> n;
	int g[x][y];
	memset(g, 0, sizeof(g));
	for(int i = 0; i < n; i++) {
		int a,b,c; cin >> a >> b >> c;
		a--; b--;
		for(int i = a; i < a+2; i++) {
			for(int j = b; j < b+2; j++) {
				g[i][j] = c;
			}
		}
	}

	for(int i = 0; i < x; i++) {
		for(int j = 0; j < y; j++) {
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
}
