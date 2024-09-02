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

void findcc (set<int>& visited, map<int, vector<int>>& mn, vector<int>& ans, int r) {
    if(visited.count(r) == 0) {
        visited.insert(r);
        ans.push_back(r);
        for(int i : mn[r]) {
            findcc(visited, mn, ans, i);
        }
    }
}

int main() {
    io("fenceplan");
    int N, M;
    cin >> N >> M;
    map<int, pair<int, int>> cc;
    in(N, 0) {
        int x, y;
        cin >> x >> y;
        cc[i+1] = make_pair(x, y);
    }
    map<int, vector<int>> mn;
    in(M, 0) {
        int x, y;
        cin >> x >> y;
        mn[x].push_back(y);
        mn[y].push_back(x);
    }

    set<int> visited;
    vector<vector<int>> mns;
    for(int i = 1; i <= N; i++) {
        if(visited.count(i) == 0) {
            vector<int> ans;
            findcc(visited, mn, ans, i);
            mns.push_back(ans);
        }
    }

    int ans = INT32_MAX;
    for(auto n : mns) {
            int a = INT32_MAX, b = 0, c = INT32_MAX, d = 0;
            for(int i : n) {
                a = min(cc[i].first, a);
                b = max(cc[i].first, b);
                c = min(cc[i].second, c);
                d = max(cc[i].second, d);
            }
            dbg << 2*(b-a+d-c) << endl;
            ans = min(ans, 2*(b-a+d-c));
        }

        cout << ans;
        return 0;
    }

