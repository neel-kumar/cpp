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

bool my_comp(pair<int, int> i, pair<int, int> j) {
    return i.second > j.second;
}

int main() {
    io("pairup");
    int N;
    cin >> N;
    vector<pair<int, int>> cows;
    int ans = 0;
    in(N, 0) {
        int x,y;
        cin >> x >> y;
        cows.push_back(make_pair(x,y));
    }

    sort(cows.begin(), cows.end(), my_comp);
    int i = 0, j = cows.size()-1;
    while(i < j) {
        ans = max(ans, cows[i].second + cows[j].second);
        if(cows[i].first > cows[j].first) {
            cows[i].first -= cows[j].first;
            cows[j].first = 0;
        } else {
            cows[j].first -= cows[i].first;
            cows[i].first = 0;
        }

        if(cows[i].first == 0) {
            i++;
        }

        if(cows[j].first == 0) {
            j--;
        }
    }

    cout << ans;

	return 0;
}

