/*
ID: n27k
TASK: ccski
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
using ld = long double;
using ll = long long;

int N, M, grid[501][501], ans;
bool vis[501][501];
vector<ii> waypts;

void ff(int rat, int x, int y) {
	if(x < 0 || y < 0 || x >= N || y >= M || vis[x][y])
		return;

	vis[x][y] = true;
	if(abs(grid[x][y] - grid[x+1][y]) <= rat) ff(rat, x+1, y);
	if(abs(grid[x][y] - grid[x-1][y]) <= rat) ff(rat, x-1, y);
	if(abs(grid[x][y] - grid[x][y+1]) <= rat) ff(rat, x, y+1);
	if(abs(grid[x][y] - grid[x][y-1]) <= rat) ff(rat, x, y-1);
}

bool checkff(int rat, int x, int y) {
	memset(vis, false, sizeof vis);
	ff(rat, x, y);
	for(auto i : waypts) {
		if(!vis[i.first][i.second])
			return false;
	}
	return true;
}

int main() {
	ifstream cin("ccski.in"); ofstream cout("ccski.out");

	ans = 0;
	int hi = 0;
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> grid[i][j];
			hi = max(hi, grid[i][j]);
		}
	}
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			int x; cin >> x;
			if(x == 1)
				waypts.push_back(make_pair(i, j));
		}
	}

	int lo = 0;
	hi++;

	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (checkff(mid, waypts[0].first, waypts[0].second)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	cout << lo;

	return 0;
}
