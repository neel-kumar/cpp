#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

int memo[1000][1000], n;
bool g[1000][1000];

int f(int i, int j) {
    if(i >= n || j >= n || g[i][j]) return 0;
    else if(memo[i][j] != 0) return memo[i][j];
    else {
        memo[i][j] = (f(i+1, j) + f(i, j+1)) % 1000000007;
        return memo[i][j];
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c; cin >> c;
            g[i][j] = (c == '*');
        }
    }

    memo[n-1][n-1] = 1;
    cout << f(0, 0) << "\n";

    return 0;
}
