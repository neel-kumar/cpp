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

void io(string f) {
    freopen((f + ".in").c_str(), "r", stdin);
    freopen((f + ".out").c_str(), "w", stdout);
}

int main() {
    io("lifeguards");
    int N;
    cin >> N;
    vector<pair<int, int>> cs;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        cs.push_back(make_pair(x, y));
    }
    sort(cs.begin(), cs.end());

    int total = 0;
    pair<int, int> ci = cs[0];
    for(int j = 0; j < N; j++) {
        if (ci.second < cs[j].first) {
            total += ci.second - ci.first;
            ci = cs[j];
        } else {
            ci.second = max(ci.second, cs[j].second);
        }
    }

    total += ci.second - ci.first;

    vector<pair<int, int>> tl;
    for(int i = 0; i < N; i++) {
        tl.push_back(make_pair(cs[i].first, i));
        tl.push_back(make_pair(cs[i].second, i));
    }

    sort(tl.begin(), tl.end());

    set<int> active;
    int as = -1; // start time when there is one lifeguard
    vector<int> at(N);
    for(int i = 0; i < tl.size(); ++i) {
        if(as != -1) {
            at[*active.begin()] += (tl[i].first - as);
            as = -1;
        }

        if(active.count(tl[i].second)) {
            active.erase(tl[i].second);
        } else {
            active.insert(tl[i].second);
        }

        if(active.size() == 1 && as == -1) {
            as = tl[i].first;
        }
    }

    int mat = at[0];
    for(auto i: at) {
        mat = min(mat, i);
    }

    cout << total - mat << endl;
}
