/*
ID: n27k TASK: task LANG: C++
http://www.usaco.org/index.php?page=viewproblem2&cpid=596
HW PROBLEM
SEARCH ENTIRE GRAPH AFTER DOUBLING

#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
using ld = long double;
using ll = long long;

int n, marker = 0;
int visited[2000][2000];

void ff(int x, int y) {

if(x < 2000 && x >= 0 && y < 2000 && y >= 0) {
if(visited[x][y] == 0) {
// visited.at(x).at(y) = marker;
visited[x][y] = marker;
ff(x+1, y);
ff(x-1, y);
ff(x, y+1);
ff(x, y-1);
}
}
}

int main() {
ifstream fin("gates.in");
//ifstream tin(".txt");
ofstream fout("gates.out");

fin >> n;
int x = 1000, y = 1000;
visited[1000][1000] = 1;
char a = ' ';
for(int i = 0; i < n; i++) {
fin >> a;
// printf("INIT #%d %c LOOP %d %d \\ ", i, a, x, y);
if(a == 'N') y += 2;
else if(a == 'S') y -= 2;
else if(a == 'E') x += 2;
else x -= 2;
// printf("(%d, %d) \\ ", x, y);
visited[x][y] = 1;
}

fout << "\nFINISHED LOOP\n";

for(int i = 0; i < 2000; i++) {
for(int j = 0; j < 2000; j++) {
if(visited[i][j] < 0) continue;
marker--;
ff(i, j);
// printf("NEXT RECURSION\n");
}
}

printf("\nAfter recursion\n");

fout << (marker+1)*(-1) << endl;

return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int arr[110];

int m[5000][5000];
int limit = 5000;
int maxX = 0, minX = limit;
int maxY = 0, minY = limit;
int posX = limit / 2;
int posY = limit / 2;
bool overLimits = false;

void checkBlank(int x, int y) {
	if (x > maxX || y > maxY || x < minX || y < minY) {
		overLimits = true;
		return;
	}

	m[x][y] = 7;

	if (m[x + 1][y] == 0)
		checkBlank(x + 1, y);
	if (m[x - 1][y] == 0)
		checkBlank(x - 1, y);
	if (m[x][y + 1] == 0)
		checkBlank(x, y + 1);
	if (m[x][y - 1] == 0)
		checkBlank(x, y - 1);
}

int main() {
	ifstream fin("gates.in");
	ofstream fout("gates.out");
	int n;
	fin >> n;

	string str;
	fin >> str;

	for (int i = 0; i < n; i++) {
		if (str[i] == 'N') {
			m[posX][posY + 1] = 1;
			m[posX][posY + 2] = 1;
			posY += 2;
		}
		if (str[i] == 'E') {
			m[posX + 1][posY] = 1;
			m[posX + 2][posY] = 1;
			posX += 2;
		}
		if (str[i] == 'S') {
			m[posX][posY - 1] = 1;
			m[posX][posY - 2] = 1;
			posY -= 2;
		}
		if (str[i] == 'W') {
			m[posX - 1][posY] = 1;
			m[posX - 2][posY] = 1;
			posX -= 2;
		}

		if (posX > maxX) maxX = posX;
		if (posY > maxY) maxY = posY;
		if (posX < minX) minX = posX;
		if (posX < minY) minY = posY;
	}

	long long count = 0;
	for (int x = minX; x <= maxX; x++)
		for (int y = minY; y < maxY; y++)
			if (m[x][y] == 0) {
				overLimits = false;
				checkBlank(x, y);
				if (!overLimits) count++;
			}

	fout << count << endl;
}
