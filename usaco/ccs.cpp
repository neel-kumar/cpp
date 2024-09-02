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

bool g[1000][1000];

void solve(set<pair<int,int>>& addcows, set<pair<int, int>>& lastcow, pair<int, int> curcow) {
    if(curcow.first < 1000 && curcow.first > 0 && curcow.second < 1000 && curcow.first > 0) {
        int ac[4][2];
        ac[0][0] = curcow.first+1;
        ac[0][1] = curcow.second;
        ac[1][0] = curcow.first-1;
        ac[1][1] = curcow.second;
        ac[2][0] = curcow.first;
        ac[2][1] = curcow.second+1;
        ac[3][0] = curcow.first;
        ac[3][1] = curcow.second-1;
        int noc = 0;
        int na = 0;
        in(4, 0) {
            if(g[ac[i][0]][ac[i][1]]) {
                na++;
            } else {
                noc = i;
            }
        }
        //dbg << "calc adj cows " << curcow.first << " " << curcow.second << endl;
        if(na == 3) {
            addcows.insert(make_pair(ac[noc][0], ac[noc][1]));
            g[ac[noc][0]][ac[noc][1]] = true;
        }

        in(4, 0) {
            if(lastcow.count(make_pair(ac[i][0], ac[i][1])) == 0 && g[ac[i][0]][ac[i][1]]) {
                lastcow.insert(make_pair(ac[i][0], ac[i][1]));
                solve(addcows, lastcow, make_pair(ac[i][0], ac[i][1]));
            }
        }
    }
}

int main() {
#ifdef DEV_ENV
    freopen("ccs.in", "r", stdin);
#endif

    int N;
    cin >> N;

    in(N, 0) {
        int x, y;
        cin >> x >> y;
        dbg << x << y << endl;
        g[x][y] = true;
        set<pair<int,int>> addcows;
        set<pair<int,int>> lastcows;
        solve(addcows, lastcows, make_pair(x, y));
        cout << addcows.size() << endl;
        for(auto i : addcows) {
            g[i.first][i.second] = false;
        }
    }

	return 0;
}

