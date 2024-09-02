/*
ID: n27k
TASK: task
LANG: C++
http://www.usaco.org/index.php?page=viewproblem2&cpid=530
*/

#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

int grid[100][100], r, c, k, memo[100][100];

int solve(int x, int y) {
    if(x >= r-1 && y >= c-1) return 1;
    if(memo[x][y] != -1) return memo[x][y];
    int ret = 0;
    for(int i = x+1; i < r; i++)
        for(int j = y+1; j < c; j++) {
            if(grid[x][y] != grid[i][j])
                ret += solve(i, j), ret %= 1000000007;
        }
    return memo[x][y] = ret;
}

int main() {
    ifstream fin("hopscotch.in");
    //ifstream tin(".txt");
    ofstream fout("hopscotch.out");
    fin >> r >> c >> k;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) {
            fin >> grid[i][j];
        }

    memset(memo, -1, sizeof memo);
    fout << solve(0, 0)%1000000007 << endl;
    return 0;

    return 0;
}
