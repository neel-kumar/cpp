#include <bits/stdc++.h>

using namespace std;

int q;

int solve(int n, int k) {
    if(n%2 == 1) {
        if(k > (n/2 + 1)) return (solve(n/2, k-(n/2 + 1)) % (n/2) + 1) * 2;
        else return k*2-1;
    } else {
        if(k > n/2) return 2*solve(n/2, k-n/2);
        else return k*2-1;
    }
}

int main() {
    cin >> q;
    for(int i = 0; i < q; i++) {
        int k, n;
        cin >> n >> k;
        int ans = solve(n, k);
        if(ans == n) ans = 1;
        else ans++;
        cout << ans << "\n";
    }
    return 0;
}
