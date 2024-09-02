#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> g, ps;
long long dp[5000][5000];

long long solve(int l, int r) {
    if(l == r) return g[l];
    else if(dp[l][r] != 0) return dp[l][r];
    else {
        dp[l][r] = max(g[l]+ps[r+1]-ps[l+1]-solve(l+1, r), g[r]+ps[r]-ps[l]-solve(l, r-1));
        return dp[l][r];
    }
}

int main() {
    cin >> n;
    ps.push_back(0);
    for(int i = 0; i < n; i++) {
        g.push_back(0);
        cin >> g[i];
        ps.push_back(ps[i]+g[i]);
    }
    cout << solve(0, n-1);
    return 0;
}
