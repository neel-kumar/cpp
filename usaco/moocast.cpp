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
#include <cmath>

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

int iscon(int x1, int y1, int x2, int y2, int bcd) {
    int xl = x1-x2;
    int yl = y1-y2;
    if(xl < 0) xl = xl*-1;
    if(yl < 0) yl = yl*-1;
    double c = sqrt(xl*xl + yl*yl);
    double bcdd = bcd;
    return c <= bcdd;
}

void dfs(pair<int, int> r, set<pair<int, int>>& nv, map<pair<int, int>, vector<pair<int, int>>>& g) {
    if(nv.count(r) == 0) {
        nv.insert(r);
        for(auto c : g[r]) {
            dfs(c, nv, g);
        }
    }
}

int main() {
    io("moocast");
    int N;
    cin >> N;
    vector<tuple<int, int, int>> cd;
    in(N, 0) {
        int x,y,z;
        cin >> x >> y >> z;
        cd.push_back(make_tuple(x, y, z));
    }
    int cds = cd.size();

    map<pair<int, int>, vector<pair<int, int>>> g;
    for(int i = 0; i < cds; i++) {
        for(int j = 0; j < cds; j++) {
            if(j == i) continue;
            else if(iscon(get<0>(cd[i]), get<1>(cd[i]), get<0>(cd[j]), get<1>(cd[j]), get<2>(cd[i]))) {
                g[make_pair(get<0>(cd[i]), get<1>(cd[i]))].push_back(make_pair(get<0>(cd[j]), get<1>(cd[j])));
            }
        }
        dbg << i << " " << g[make_pair(get<0>(cd[i]), get<1>(cd[i]))].size() << endl;
    }
    
    int ans = 0;
    for(int i = 0; i < cds; i++) {
        set<pair<int, int>> nv;
        dfs(make_pair(get<0>(cd[i]), get<1>(cd[i])), nv, g);
        int nvs = nv.size();
        ans = max(ans, nvs);
    }
    cout << ans;

	return 0;
}

