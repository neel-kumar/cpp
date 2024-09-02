#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

ll n, m, a[100000];
map<ll, int> memo;

int main() {
    cin >> n >> m;
    for(ll i = 0; i < n; i++) {
        ll xi; cin >> xi;
        a[i] = xi;
    }

    if(a[0] != 0) {
        memo[a[0]] = 1;
    } else {
        for(ll i = 1; i <= m; i++) {
            memo[i] = 1;
        }
    }

    for(ll i = 1; i < n; i++) {
        if(a[i] != 0) {
            //prllf("a[%d] NOT 0: ", i);
            ll num = 0;
            for(const auto &e : memo) {
                //prllf("(%d, %d) ", e.first, e.second);
                if(!(e.first-a[i] > 1 || e.first-a[i] < -1))
                    num = (num+e.second) % 1000000007;
                memo[e.first] = 0;
            }
            memo[a[i]] = num;
        } else {
            //prllf("a[%d] IS 0: ", i);
            vector<pair<ll, int>> incr;
            for(const auto &e : memo) {
                if(e.second == 0) continue;
                //prllf("(%d, %d) ", e.first, e.second);
                if(e.first+1 <= m) incr.push_back(make_pair(e.first+1, e.second));
                if(e.first-1 > 0) incr.push_back(make_pair(e.first-1, e.second));
            }
            for(auto e : incr)
                memo[e.first] = (memo[e.first]+e.second) % 1000000007;
        }
        //prllf("\n");
        /*prllf("After i = %d, memo is", i);
        for(const auto &e : memo) {
            prllf(" %d -> %d", e.first, e.second);
        }
        prllf("\n");
        */
    }

    ll ans = 0;
    for(const auto &e : memo) {
        //prllf("FINISH");
        //prllf("(%d, %d) ", e.first, e.second);
        // ans += e.second;
        ans = (ans + e.second) % 1000000007;
    }
    cout << (ans % 1000000007) << "\n";

    return 0;
}
