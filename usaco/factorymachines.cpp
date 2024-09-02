#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp> // Common file
using namespace __gnu_pbds;
// Declaring ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// Segment Tree st
const int stn = 1 << 3; // size of st, power of 2
int st[stn];
int sum(int a, int b) {
    a += stn; b += stn;
    int s = 0;
    while (a <= b) {
        if (a%2 == 1) s += st[a++];
        if (b%2 == 0) s += st[b--];
        a /= 2; b /= 2;
    }
    return s;
}
void add(int k, int x) {
    k += stn;
    st[k] += x;
    for (k /= 2; k >= 1; k /= 2) {
        st[k] = st[2*k]+st[2*k+1];
    }
}

ll n, t;
vector<ll> ks;

int main() {
    cin >> n >> t;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        ks.push_back(k);
    }

    ll l = 0, r = 1e18;
    ll ans = r;
    while(l <= r) {
        ll mid = l + (r-l)/2;
        ll prod = 0;
        for(int k : ks) {
            prod += mid/k;
            if(prod >= t) {
                break;
            }
        }
        if(prod < t) {
            l = mid+1;
        } else {
            ans = min(ans, mid);
            r = mid-1;
        }
    }
    
    cout << ans << "\n";

    return 0;
}
