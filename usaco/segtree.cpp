/*
ID: n27k
TASK: task
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
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

int main() {
    ifstream fin("task.in");
    //ifstream tin(".txt");
    ofstream fout("task.out");

    return 0;
}
