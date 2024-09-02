#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;


#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp> // Common file
using namespace __gnu_pbds;

// Declaring ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update>
    ordered_set;
ordered_set inset, outset;


const int maxN = 200000;
const int stN = 1 << 18;
int in[maxN], con[maxN], st[2*stN+1];
pair<int, int> xs[maxN];
int n;
map<int, int> coordcomp;
vector<int> lpts;

bool ccomp(tuple<int, int, int> a, tuple<int, int, int> b) {
    if(get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
    else return get<1>(a) > get<1>(b);
}

bool ccomp2(tuple<int, int, int> a, tuple<int, int, int> b) {
    if(get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b);
    else return get<1>(a) < get<1>(b);
}

int sum(int a, int b) {
    a += n; b += n;
    int s = 0;
    while (a <= b) {
        if (a%2 == 1) s += st[a++];
        if (b%2 == 0) s += st[b--];
        a /= 2; b /= 2;
    }
    return s;
}

void add(int k, int x) {
    k += n;
    st[k] += x;
    for (k /= 2; k >= 1; k /= 2) {
        st[k] = st[2*k]+st[2*k+1];
    }
}

int main() {
    cin >> n;
    tuple<int, int, int> xs[n];
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        xs[i] = make_tuple(a, b, i);
        lpts.push_back(b);
    }

    sort(lpts.begin(), lpts.end());
    for(int i = 1; i <= n; i++) {
        coordcomp[lpts[i]] = i;
    }

    sort(xs, xs+n, ccomp);
    for(int i = 0; i < n; i++) {
        in[get<2>(xs[i])] = sum(coordcomp[get<1>(xs[i])], n);
        add(coordcomp[get<1>(xs[i])], 1);
    }

    for(int i = 0; i < 2*stN; i++) st[i] = 0;

    sort(xs, xs+n, ccomp2);
    for(int i = 0; i < n; i++) {
        con[get<2>(xs[i])] = sum(0, coordcomp[get<1>(xs[i])]);
        add(coordcomp[get<1>(xs[i])], 1);
    }

    for(int i = 0; i < n; i++) cout << con[i] << " ";
    cout << "\n";
    for(int i = 0; i < n; i++) cout << in[i] << " ";

    return 0;
}
