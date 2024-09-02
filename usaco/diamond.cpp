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

#define DEV_ENV

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

bool mycomp(pair<int,int> i, pair<int,int> j) {
    return i.second < j.second;
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

    sort(d.begin(), d.end());

    vector<pair<int, int>> dk;
    int s = 0;
    dk.push_back(make_pair(d[0], 1));
    int ds = d.size();
    for(int i = 1; i < ds; i++) {
        if(d[i] - dk[s].first <= K) {
            dbg << "same case " << d[i] << endl;
            dk[s].second++;
        } else {
            dbg << "diff case " << d[i] << " " << dk[s].first << endl;
            dk.push_back(make_pair(d[i], 1));
            s++;
        }
    }

    dbg << dk.size() << endl;
    sort(dk.begin(), dk.end(), mycomp);
    int dks = dk.size();
    cout << (dk.at(dks-1).second + dk.at(dks-2).second);

	return 0;
}

