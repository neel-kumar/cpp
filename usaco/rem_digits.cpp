#include <bits/stdc++.h>
#include <climits>

using namespace std;
using ld = long double;
using ll = long long;

int n;
int memo[1000001];

int main() {
    cin >> n;
    memo[0] = 0;
    for(int i = 1; i <= n; i++) {
        int tn = i;
        memo[i] = INT32_MAX;
        while(tn > 0) {
            int d = tn%10;
            tn /= 10;
            if(d == 0) continue;
            memo[i] = min(memo[i], memo[i-d]+1);
        }
    }
    cout << memo[n] << "\n";

    return 0;
}
