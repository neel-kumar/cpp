#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>
using namespace std;
#define int long long
using i2 = pair<int, int>;
using i3 = tuple<int, int, int>;
const int inf = 1e18;
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        set<i2> s;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            ++x;
            auto it = s.lower_bound({x, 0});
            // cout << (it != s.begin()) << endl;
            i2 p = {x, it == s.begin() ? 1 : prev(it)->second + 1};
            // cout << p.first << " " << p.second << endl;
            while ((it = s.lower_bound(p)) != s.end()) {
                if (it->second > p.second) break;
                s.erase(it);
            }
            p.first--;
            if (it == s.begin() || prev(it)->second < p.second) s.insert(p);
            // for (pii p : s) cout << p.first << ":" << p.second << " ";
            // cout << endl;
        }
        cout << n - s.rbegin()->second << endl;
    }
    return 0;
}
