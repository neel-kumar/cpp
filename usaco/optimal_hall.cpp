#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, M, X, Y;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> X >> Y;

	int mx = 0;
	int grid[N+1][M+1];
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			cin >> grid[i][j];
			mx = max(mx, grid[i][j]);
		}
	}

	int l = 0, r = mx;
	while(l < r) {
		int mid = (l+r+1)/2;

		int ps[N+1][M+1];
		for(int i = 0; i <= N; i++)
			for(int j = 0; j <= M; j++)
				ps[i][j] = 0;

		for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) ps[i][j] = (grid[i][j] < mid) + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];

		bool works = false;
		for (int i = 1; i <= N-X+1; i++) {
			for (int j = 1; j <= M-Y+1; j++) {
				int i2 = i+X-1, j2 = j+Y-1;
				if( (ps[i2][j2] - ps[i-1][j2] - ps[i2][j-1] + ps[i-1][j-1]) == 0) works = true;
				if(works) {
					break;
				}
			}
		}

		if(works) l = mid;
		else r = mid-1;
	}
	cout << l << endl;

	return 0;
}
