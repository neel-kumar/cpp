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

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int f = 0;
        pair<int, int> ci;
        bool fl = false;
        for(int j = 0; j < N; j++) {
            if(i == j) {
                continue;
            } else if (!fl) {
                ci = cs[j];
                fl = true;
            } else if (ci.second < cs[j].first) {
                f += ci.second - ci.first;
                ci = cs[j];
            } else if (cs[j].second > ci.second) {
                ci.second = cs[j].second;
            }
        }
        f += ci.second - ci.first;
        ans = max(ans, f);
    }
    cout << ans;
}

