#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

int main() {
    ll x, n; cin >> x >> n;
    vector<ll> cvals;
    for(int i = 0; i < x; i++) {
        int j; cin >> j;
        cvals.push_back(j);
    }
    ll memo[1000001];
    memo[0] = 1;

    for(ll i = 1; i <= n; i++) {
        memo[i] = 0;
        for(ll j : cvals) {
            if(i - j >= 0)
                memo[i] += memo[i-j];
            memo[i] = memo[i];
        }
        memo[i] = memo[i];
    }

    cout << memo[n] << "\n";;

    return 0;
}
