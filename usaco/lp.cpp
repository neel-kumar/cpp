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

int main() {
#ifdef DEV_ENV
    freopen("lp.in", "r", stdin);
#endif
    int N;
    cin >> N;
    string l;
    cin >> l;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        bool good = false;
        for(int j = i + 2; j < N; j++) {
            if(good) break;
            int ng = 0, nh = 0;
            for(int a = i; a <= j; a++) {
                if(l[a] == 'G') ng++;
                else nh++;
            }
            if(ng == 1 || nh == 1) ans++;
            else if(ng != 0 && nh != 0) good = true;
        }
    }

    cout << ans;
	return 0;
}

