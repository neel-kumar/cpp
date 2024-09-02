#include <bits/stdc++.h>

using namespace std;
using lb = long double;
using ll = long long;

int main() {
    int n; cin >> n;
    int ans = 0, l = 0, r = 0;
    set<int> nums;
    int ks[n];
    cin >> ks[0];
    while(r < n) {
        if(nums.count(ks[r]) == 0) {
            nums.insert(ks[r]);
            r++;
            if(r < n) cin >> ks[r];
            ans = max(ans, r-l);
        } else {
            nums.erase(ks[l]);
            l++;
        }
        //cout << l << " " << r << "\n";
    }
    cout << ans << "\n";

    return 0;
}
