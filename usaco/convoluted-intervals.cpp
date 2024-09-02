#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

ll n, m, kans[10002], nd[5001], st[5001];

int main() {
    cin >> n >> m;
    for(ll i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        st[a]++;
        nd[b]++;
    }

    for(ll i = 0; i <= m; i++) {
        for(ll j = 0; j <= m; j++) {
            kans[i+j] += st[i]*st[j];
            kans[i+j+1] -= nd[i]*nd[j];
        }
    }

    cout << kans[0] << "\n";
    for(ll i = 1; i <= 2*m; i++) {
        kans[i] =  kans[i]+kans[i-1];
        cout << kans[i] << "\n";
    }

    return 0;
}
