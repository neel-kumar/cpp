/*
ID: n27k
TASK: task
LANG: C++
http://www.usaco.org/index.php?page=viewproblem2&cpid=492
IMPLEMENT WITH DP BOTTOM UP
*/

/*int f(int i, int k) {
    if(i == n-1) return 0;
    if(memo[i][k] != -1) return memo[i][k];
    int ret = INT32_MAX;
    for(int a = i+1; a <= min(n-1, k+i); a++) {
        ret = min(ret, d(i, a) + f(a, a-i));
    }
    return ret;
}

#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

int checkpts[500][2], n, k, memo[300][300][300];

int d(int x, int y) {
    return abs(checkpts[x][0] - checkpts[y][0]) + abs(checkpts[x][1] - checkpts[y][1]);
}

int f(int i, int k, int p) {
    if(memo[i][k][p] != -1) return memo[i][k][p];
    if(i == n-1) return memo[i][k][p] = d(i, p);
    if(k == 0) return memo[i][k][p] = d(i, p) + f(i+1, k, i);
    return memo[i][k][p] = min(d(i, p) + f(i+1, k, i), f(i+1, k-1, p));
}

int main() {
    ifstream fin("marathon.in");
    //ifstream tin(".txt");
    ofstream fout("marathon.out");

    fin >> n >> k;
    for(int i = 0; i < n; i++) {
        fin >> checkpts[i][0] >> checkpts[i][1];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
    memset(memo, -1, sizeof memo);
    fout << f(0, k, 0) << endl;

    return 0;
}
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    ifstream fin("marathon.in");
    ofstream fout("marathon.out");
  int x[500] = {}, y[500] = {}, dp[500][500] = {};

  int n, k; fin >> n >> k;
  for (int i = 0; i < n; i++) fin >> x[i] >> y[i];

  for (int i = 0; i < k + 1; i++)
    for (int j = 0; j < n; j++)
      dp[i][j] = 2000000000;

  dp[0][0] = 0;
  for (int i = 0; i <= k; i++)
    for (int j = 0; j < n; j++)
      for (int nextJ = j + 1; nextJ < n && i + (nextJ - j - 1) <= k; nextJ++) {
        int nextI = i + (nextJ - j - 1);
        int dist = abs(x[j] - x[nextJ]) + abs(y[j] - y[nextJ]);
        dp[nextI][nextJ] = min(dp[nextI][nextJ], dp[i][j] + dist);
      }
  fout << dp[k][n - 1] << endl;
}
