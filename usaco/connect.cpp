#include <bits/stdc++.h>
using namespace std;

int n;
int cx, cy, wx, wy;
int vis[50][50];
int g[50][50];
vector<array<int, 2>> curr, wish;

void flood_fill_curr(int x, int y) {
	if(x < 0 || y < 0 || x >= n || y >= n) return;
	if(vis[x][y]) return;
	if(g[x][y] == 1) return;
	vis[x][y] = 1;
	array<int, 2> add_arr; add_arr[0] = x; add_arr[1] = y;
	curr.push_back(add_arr);

	flood_fill_curr(x-1, y);
	flood_fill_curr(x+1, y);
	flood_fill_curr(x, y+1);
	flood_fill_curr(x, y-1);
}

void flood_fill_wish(int x, int y) {
	if(x < 0 || y < 0 || x >= n || y >= n) return;
	if(vis[x][y]) return;
	if(g[x][y] == 1) return;
	// deal with NO TUNNEL NEEDED
	vis[x][y] = 2;
	array<int, 2> add_arr; add_arr[0] = x; add_arr[1] = y;
	wish.push_back(add_arr);

	flood_fill_wish(x+1, y);
	flood_fill_wish(x-1, y);
	flood_fill_wish(x, y+1);
	flood_fill_wish(x, y-1);
}

int main() {
	cin >> n >> cx >> cy >> wx >> wy;
	cx--; cy--; wx--; wy--;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			char x; cin >> x;
			if(x == '0') g[i][j] = 0;
			else g[i][j] = 1;
		}
	}

	flood_fill_curr(cx, cy);
	flood_fill_wish(wx, wy);

	if(wish.size() == 0) {
		cout << "0\n";
		return 0;
	}
	int ans = INT_MAX;
	for(auto i : curr) {
		for(auto j : wish) {
			if(i == j) {
				cout << "0\n";
				return 0;
			}
			int a = i[0] - j[0]; a = a*a;
			int b = i[1] - j[1]; b = b*b;
			ans = min(ans, a+b);
		}
	}
	cout << ans << endl;

	return 0;
}
