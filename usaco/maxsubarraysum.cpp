#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;
    ll rs = 0, ans = INT_MIN, m = 0;
    for(ll i = 0; i < n; i++) {
        ll j; cin >> j;
        rs += j;
        ans = max(ans, rs-m);
        m = min(m, rs);
    }

    cout << ans << "\n";

    return 0;
}
