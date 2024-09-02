#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

int main() {
    int n, k; cin >> n >> k;

    int xs[200000];
    int l = 0, r = -1, ans = 0;
    map<int, int> c;
    c[-1] = 0;
    for(l = 0; l < n; l++) {
        while(c[-1] <= k) {
            if(r >= n) break;
            r++;
            cin >> xs[r];
            if(c.count(xs[r]) == 0 || c[xs[r]] == 0) {
                c[xs[r]] = 0;
                c[-1]++;
            }
            c[xs[r]]++;
        }
        c[-1]--;
        c[xs[r]]--;
        ans += r-l+1;
        printf("%d %d %d\n", l, r, ans);
        c[xs[l]]--;
        if(c[xs[l]] == 0) c[-1]--;
    }

    printf("%d\n", ans);
    return 0;
}
