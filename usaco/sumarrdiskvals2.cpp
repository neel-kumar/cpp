#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

int main() {
    int n, k; cin >> n >> k;
    vector<int> x;
    for(int i = 0; i < n; i++) {
        int xi; cin >> xi;
        x.push_back(xi);
    }

    // 1 2 1
    ll l = 0, r = 0, ans = 0, count = 0;
    map<int, ll> c;
    for(l = 0; l < n; l++) {
        while(count <= k && r < n) {
            if(count == k && c[x[r]] == 0) break;
            if(c.count(x[r]) == 0 || c[x[r]] == 0) {
                c[x[r]] = 0;
                count++;
            }
            c[x[r]]++;
            r++;
        }
        ans += r-l;
        // printf("%ld %ld %ld\n", l, r, ans);

        c[x[l]]--;
        if(c[x[l]] == 0) count--; 
    }

    cout << ans << "\n";

    return 0;
}
