#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

bool in[200000], con[200000];
pair<int, int> xs[200000];
int n;

bool ccomp(tuple<int, int, int> a, tuple<int, int, int> b) {
    if(get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
    else return get<1>(a) > get<1>(b);
}

bool ccomp2(tuple<int, int, int> a, tuple<int, int, int> b) {
    if(get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b);
    else return get<1>(a) < get<1>(b);
}

int main() {
    cin >> n;
    tuple<int, int, int> xs[n];
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        xs[i] = make_tuple(a, b, i);
    }

    sort(xs, xs+n, ccomp);
    int rm = INT32_MIN;
    for(int i = 0; i < n; i++) {
        if(rm >= get<1>(xs[i])) {
            in[get<2>(xs[i])] = true;
        } else {
            rm = get<1>(xs[i]);
        }
    }

    sort(xs, xs+n, ccomp2);
    rm = INT32_MAX;
    for(int i = 0; i < n; i++) {
        if(rm <= get<1>(xs[i])) {
            con[get<2>(xs[i])] = true;
        } else {
            rm = get<1>(xs[i]);
        }
    }

    for(int i = 0; i < n; i++) cout << con[i] << " ";
    cout << "\n";
    for(int i = 0; i < n; i++) cout << in[i] << " ";

    return 0;
}
