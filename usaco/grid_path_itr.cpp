#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

int memo[1000][1000], n;
bool grid[1000][1000];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c; cin >> c;
            grid[i][j] = (c == '*');
        }
    }

    if(grid[n-1][n-1]) {
        cout << "0\n";
        return 0;
    }
    memo[n-1][n-1] = 1;
    for(int i = n-1; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {
            if(grid[i][j]) continue;
            if(i+1 < n) memo[i][j] += memo[i+1][j];
            if(j+1 < n) memo[i][j] += memo[i][j+1];
            memo[i][j] = memo[i][j] % 1000000007;
            //cout << memo[i][j] << "\n";
        }
    }
    cout << memo[0][0] << "\n";

    return 0;
}
