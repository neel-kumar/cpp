#include <bits/stdc++.h>

using namespace std;

int row[4]{0, 1, 0, -1};
int col[4]{1, 0, -1, 0};
char maze[55][55];
int gcount = 0, n, m;

void ff(int x, int y) {
	if(x < 0 || x >= n || y < 0 || y >= m)
		return;
	if(maze[x][y] == '#')
		return;
	if(maze[x][y] == '-')
		return;
	// ^ all non valid
	if(maze[x][y] == 'G')
		gcount--;
	maze[x][y] = '-'; // visited
	ff(x-1, y);
	ff(x+1, y);
	ff(x, y-1);
	ff(x, y+1);
}

void setgs() {
	gcount = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(maze[i][j] == 'G')
				gcount++;
			if(maze[i][j] == 'B') {
				for(int x = 0; x < 4; x++) {
					const int ni = i+row[x];
					const int nj = j+col[x];
					if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
						if(maze[ni][nj] == 'G') {
							cout << "No\n";
							return;
						}

						if(maze[ni][nj] == '.')
							maze[ni][nj] = '#';
					}
				}
			}
		}
	}
	ff(n-1, m-1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maze[i][j] == 'G') {
				cout << "No\n";
				return;
			}
		}
	}
	cout << "Yes\n";
	return;
	if(!gcount)
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main() {
	int T; cin >> T;
	while(T--) {
		// memset(maze, '.', sizeof(maze));
		cin >> n >> m;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) cin >> maze[i][j];

		setgs();
	}

		return 0;
}
