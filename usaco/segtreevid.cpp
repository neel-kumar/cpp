#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

// Segment Tree st
const int stn = 1 << 2; // size of st, power of 2
int st[2*stn];
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

int main() {
    add(0, 3);
    add(3, 2);
    add(2, 1);
    cout << "Sum of indices 1 to 3: " << sum(1, 3) << "\n";
    add(1, 10);
    cout << "Sum of indices 1 to 3 (AFTER add): " << sum(1, 3) << "\n";

    return 0;
}
