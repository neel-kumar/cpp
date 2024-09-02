#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <list>
#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

#define in(N, ii) for(int i = ii; i < N; i++)

// #define DEV_ENV

#ifdef DEV_ENV
#define dbg cout << "DEBUG: "
#else
#define dbg if(true) {} else cout
#endif

int N, K;

void io(string f) {
    freopen((f + ".in").c_str(), "r", stdin);
#ifndef DEV_ENV
    freopen((f + ".out").c_str(), "w", stdout);
#endif
}

int lls(int i, const vector<int>& d, int K) {
    int j = i;
    int ds = d.size();
    while(j < ds && d[j] - d[i] <= K) {
        j++;
    }
    return j-i;
}

int main() {
    io("diamond");
    cin >> N >> K;
    vector<int> d;
    in(N, 0) {
        int x;
        cin >> x;
        d.push_back(x);
    }
    int ds = d.size();

    sort(d.begin(), d.end());

    vector<int> dls(ds);
    for(int i = 0; i < ds; i++) {
        dls[i] = lls(i, d, K);
    }

    vector<int> rdls(ds);
    rdls[dls.size() - 1] = dls[dls.size() - 1];

    for(int i = dls.size() - 2; i >= 0; i--) {
        rdls[i] = max(dls[i], rdls[i + 1]);
    }

    int ans = 0;
    for(int i = 0; i < ds; i++) {
        ans = max(ans, dls[i] + rdls[i+dls[i]]);
    }

    cout << ans;
}
