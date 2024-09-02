#include <bits/stdc++.h>
#include <utility>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
using ld = long double;
using ll = long long;

map<int, vi> g;
int val[100001], n, ans;
map<int, vector<ii>> ansm;

int f(int prev, int b) {
    int ret = val[b];
    int fr = -1;
    vi pos, neg;
    for(int i : g[b]) {
        if(i == prev)
            continue;
        fr = f(b, i);
        if(fr == 0)
            n--;
        else {
            if(fr > 0)
                pos.push_back(i);
            else
                neg.push_back(i);
        }

        ret += fr;
    }
    return ret;
}

int main() {
    cin >> n;
    ans = n-1;
    int tot = 0;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        tot += a;
        val[i+1] = a;
    }
    int target = tot/n;
    for(int i = 0; i < n; i++) {
        val[i+1] = val[i+1]-target;
    }

    for(int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }

    f(-1, 1);
    cout << ans << endl;

    return 0;
}
