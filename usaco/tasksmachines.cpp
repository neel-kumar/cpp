#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

ll n;
pair<ll, ll> tasks[200000];

int main() {
    cin >> n;
    for(ll i = 0; i < n; i++)
        cin >> tasks[i].first >> tasks[i].second;

    sort(tasks, tasks+n);

    ll ans = 0, t = 0;
    for(ll i = 0; i < n; i++) {
        t += tasks[i].first;
        ans += tasks[i].second-t;
    }

    cout << ans << "\n";

    return 0;
}
