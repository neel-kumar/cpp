#include <bits/stdc++.h>
#include <cstdint>

using namespace std;
using ld = long double;
using ll = long long;

int a, b, memo[501][501];

int f(int i, int j) {
    if(i == j) return 0;
    else if(memo[i][j] != 0) return memo[i][j];
    else {
        //printf("(%d, %d) ", i, j);
        int m = INT16_MAX;
        if(i > 1) {
            for(int a = 1; a < i; a++) {
                m = min(m, f(a, j)+f(i-a, j));
            }
        }
        if(j > 1) {
            for(int a = 1; a < j; a++) {
                m = min(m, f(i, a)+f(i, j-a));
            }
        }
        memo[i][j] = m+1;
        return m+1;
    }
}

int main() {
    cin >> a >> b;
    cout << f(a, b) << "\n";

    return 0;
}
