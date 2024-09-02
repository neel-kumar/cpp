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

int g[50][50];
int N, K;
int p;

void solve(int x, int y, int prev, int kt) {
    if(kt < 0) {
    } else if(x == N-1 && y == N-1) {
        p++;
    } else {
        // Down
        if(g[x+1][y] != 1 && x+1 <= N-1) {
            int ktt = kt;
            if(prev == 'R') {
                ktt--;
            }
            solve(x+1, y, 'D', ktt);
        }
        // Right
        if(g[x][y+1] != 1 && y+1 <= N-1) {
            int ktt = kt;
            if(prev == 'D') {
                ktt--;
            }
            solve(x, y+1, 'R', ktt);
        }
    }
}



int main() {
#ifdef DEV_ENV
    freopen("wh.in", "r", stdin);
#endif
    int T;
    cin >> T;
    in(T, 0) {
        cin >> N >> K;
        dbg << "T: " << i << " N: " << N << " K: " << K << endl;
        for(int x = 0; x < N; x++) {
            for(int y = 0; y < N; y++) {
                char a;
                cin >> a;
                if(a == '.') g[x][y] = 0;
                else g[x][y] = 1;
            }
        }
        p = 0;
        solve(0, 0, ' ', K);
        cout << p << endl;
    }
	return 0;
}

