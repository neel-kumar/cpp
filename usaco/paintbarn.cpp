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

int barn[1000][1000];
int ans = 0;

void io(string f) {
    freopen((f + ".in").c_str(), "r", stdin);
#ifndef DEV_ENV
    freopen((f + ".out").c_str(), "w", stdout);
#endif
}

void fillbarn(int x1, int y1, int x2, int y2) {
    for(int i = x1; i < x2; i++) {
        for(int j = y1; j < y2; j++) {
            dbg << "FILL " << i << " " << j << " " << barn[i][j] << endl;
            barn[i][j]++;
        }
    }
}

int main() {
    io("paintbarn");
    int N, K;
    cin >> N >> K;

    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            barn[i][j] = 0;
        }
    }

    in(N, 0) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        fillbarn(x1, y1, x2, y2);
    }
    
    int ans = 0;
    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            if(barn[i][j] == K) {
                dbg << "ANS " << i << " " << j << endl;
                ans++;
            }
        }
    }

    cout << ans;
	return 0;
}
