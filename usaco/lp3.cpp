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
    long long N;
    cin >> N;
    int li[N];
    in(N, 0) {
        char x;
        cin >> x;
        li[i] = x;
    }
    long long ans = 0;
    for(int i = 0; i < N; i++) {
        int tng = 0, tnh = 0;
        for(int a = i; a <= i+2; a++) {
            if(li[a] == 'G') tng++;
            else tnh++;
        }
        for(int j = i + 2; j < N; j++) {
            if(tng == 1 || tnh == 1) ans++;
            else if(tng != 0 && tnh != 0) break;
            // dbg << i << " " << j << " " << tng << " " << tnh << endl;
            if(li[j+1] == 'G') tng++;
            else tnh++;
        }
    }

    cout << ans;
	return 0;
}
