#include <bits/stdc++.h>

using namespace std;
using lb = long double;
using ll = long long;

int main() {
    int n; cin >> n;
    multiset<int> ts;
    while(n--) {
        int b; cin >> b;
        auto ub = ts.upper_bound(b);
        if(ub != ts.end())
            ts.erase(ub);
        ts.insert(b);
    }
    cout << ts.size() << "\n";

    return 0;
}
