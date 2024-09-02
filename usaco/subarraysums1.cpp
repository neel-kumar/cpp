#include <bits/stdc++.h>
// #include <cstdio>

using namespace std;
using ld = long double;
using ll = long long;

int main() {
    ll n, x; cin >> n >> x;
    map<ll, ll> pset;
    ll rs = 0, ans = 0;
    for(ll i = 0; i < n; i++) {
        if(pset.count(rs) == 0) pset[rs] = 0;
        pset[rs]++;
        ll a; cin >> a;
        rs += a;
        if(pset.count(rs-x) != 0) ans += pset[rs-x];
    }
    cout << ans << "\n";

    return 0;
}
