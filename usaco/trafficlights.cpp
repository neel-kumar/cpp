#include <bits/stdc++.h>

using namespace std;
using lb = long double;
using ll = long long;

int main() {
    int x, n; cin >> x >> n;
    multiset<int> inters;
    set<int> tls;
    inters.insert(x);
    tls.insert(0);
    tls.insert(x);
    while(n--) {
        int ntl; cin >> ntl;
        auto itl = tls.lower_bound(ntl);
        int r = *(itl), l = *(--itl);
        tls.insert(ntl);
        inters.erase(inters.find(r-l));
        inters.insert(ntl-l);
        inters.insert(r-ntl);
        //cout << r-l << " " << ntl-l << " " << r-ntl << " STUFF ";
        cout << *(inters.rbegin()) << " ";
    }

    return 0;
}
