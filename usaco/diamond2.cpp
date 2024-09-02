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

int lls(int i, vector<int> d, int K) {
    int j = i;
    int ds = d.size();
    while(j < ds && d[j] - d[i] <= K) {
        j++;
    }
    return j-i;
}

int ls(int i, vector<int> d, int K) {
    dbg << "LS " << i << endl;
    int ans = 0;
    int ds = d.size();
    for(int j = i; j < ds; j++) {
        int k = j;
        while(k < ds && d[k] - d[j] <= K) {
            k++;
        }
        dbg << k << " " << j << endl;
        ans = max(ans, k-j);
    }
    dbg << "LS END" << endl;
    return ans;
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
    
    int ans = 0;
    int ds = d.size();
    for(int i = 0; i < ds; i++) {
        int lsi = lls(i, d, K);
        dbg << d[i] << " " << lsi << endl;
        ans = max(ans, lsi + ls(i+lsi, d, K));
    }

    cout << ans;
}
