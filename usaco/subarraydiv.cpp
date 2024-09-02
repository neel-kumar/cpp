#include <bits/stdc++.h>
// #include <cstdio>

using namespace std;
using ld = long double;
using ll = long long;

int main() {
    ll n; cin >> n;
    map<ll, ll> pset;
    ll rs = 0, ans = 0;
    for(ll i = 0; i < n; i++) {
        if(pset.count(rs%n) == 0) pset[rs%n] = 0;
        pset[rs%n]++;
        ll a; cin >> a;
        rs += a;
        // Take care of negative values
        rs = (rs%n + n) % n;
        if(pset.count(rs) != 0) ans += pset[rs];
    }
    cout << ans << "\n";

    return 0;
}
