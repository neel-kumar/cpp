#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

int main() {
    ll n; cin >> n;
    ll memo[1000001];
    memo[0] = 1;

    for(ll i = 1; i <= n; i++) {
        memo[i] = 0;
        for(ll j = 1; j <= 6; j++) {
            if(i - j >= 0)
                memo[i] += memo[i-j];
            memo[i] = memo[i] % 1000000007;
        }
        memo[i] = memo[i] % 1000000007;
    }

    cout << memo[n] << "\n";;

    return 0;
}
