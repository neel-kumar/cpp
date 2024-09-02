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

//#define DEV_ENV

#ifdef DEV_ENV
#define dbg cout << "DEBUG: "
#else
#define dbg if(true) {} else cout
#endif

void io(string f) {
    freopen((f + ".in").c_str(), "r", stdin);
#ifndef DEV_ENV
    freopen((f + ".out").c_str(), "w", stdout);
#endif
}

int main() {
    io("div7");
    int N;
    cin >> N;
    int cids[50000];
    in(N, 0) {
        int id;
        cin >> id;
        cids[i] = id;
    }

    long long idps[50001];
    long long sum = 0;
    idps[0] = sum;
    map<long long, int> ps;
    in(N, 0) {
        sum += cids[i];
        idps[i+1] = sum;
        ps[sum] = i;
    }

    map<int, int> i2r;
    int maxl = 0;
    for(int i = 0; i <= N; i++) {
        if(i2r.count(idps[i] % 7) == 0) {
            i2r[idps[i] % 7] = i;
        } else {
            maxl = max(maxl, i - i2r[idps[i] % 7]);
        }
    }

    cout << maxl;
    return 0;
}


