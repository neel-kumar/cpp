#include <bits/stdc++.h>
#include <utility>

using namespace std;
using ld = long double;
using ll = long long;
const ll MOD = 1e9L + 7L; // 1000000007;

int n, target;
vector<int> coins;
map<ll, ll> ans;

int main() {
    cin >> n;

    ll sum = (n*(n+1))/2;
    ll key = sum / 2;

    ll count = 0;

    ans[0] = 1;
    for(int i = 1; i < n ; i++) {
        vector<pair<ll, ll>> mod;
        for(auto j : ans) {
            if(j.first+i == key) {
                count += (j.second % MOD);
                count %= MOD;
            }
            mod.push_back(make_pair(j.first+i, j.second));
        }
        for(auto j : mod) {
            if(ans.count(j.first) == 0) ans[j.first] = 0;

            // ans[j.first] += j.second;
            // ans[j.first] %= MOD;
            ans[j.first] = (ans[j.first] % MOD + j.second % MOD) % MOD;
            // ans[j.first] = (ans[j.first] + j.second ) ;
        }
    }

    // cout << (ans[(n*(n+1))/4])/2 << "\n";

    cout << ((sum % 2 != 0 || ans.count(key) == 0) ? 0 : (ans[key]) % MOD) << endl;

    // cout << ((sum % 2 != 0 || ans.count(key) == 0) ? 0 : (count % MOD) ) << endl;

    return 0;
}
