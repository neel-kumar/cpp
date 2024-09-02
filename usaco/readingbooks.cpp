#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

ll n, sum = 0, m = 0;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll b; cin >> b;
        m = max(b, m);
        sum += b;
    }
    cout << max(2*m, sum);

    return 0;
}
