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

bool all0(int* d, int N) {
    in(N, 0) {
        if(d[i] != 0) {
           return false; 
        }
    }
    return true;
}

int main() {
#ifdef DEV_ENV
    freopen("ac.in", "r", stdin);
#endif
    int N;
    cin >> N;
    int t[100000];
    int ini[100000];
    int d[100000];
    in(N, 0) {
        int x;
        cin >> x;
        t[i] = x;
    }
    in(N, 0) {
        int x;
        cin >> x;
        ini[i] = x;
        d[i] = t[i]-ini[i];
    }
    int ans = 0;
    while(!all0(d, N)) {
        bool ispos = true;
        int f = -1, l;
        in(N, 0) {
            if(d[i] > 0 && f == -1) {
                ispos = true;
                f = i;
                break;
            } else if(d[i] < 0 && f == -1) {
                ispos = false;
                f = i;
                break;
            }
        }
        for(int i = N-1; i >= 0; i--) {
            if(ispos && d[i] > 0) {
                l = i;
                break;
            } else if(!ispos && d[i] < 0) {
                l = i;
                break;
            }
        }
        int nc;
        if(ispos) {
            nc = -1 * min(d[f], d[l]);
            ans = ans - nc;
        } else {
            nc = -1 * max(d[f], d[l]);
            ans = ans + nc;
        }
        for(int i = f; i <= l; i++) {
            d[i] = d[i] + nc;
        }
    }

    cout << ans;
	return 0;
}

