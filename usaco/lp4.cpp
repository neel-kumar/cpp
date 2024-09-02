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
        if(x == 'G') li[i] = 1;
        else li[i] = -1;
    }
    int lip[N+1];
    int x = 0;
    in(N, 0) {
        lip[i] = x;
        x = x + li[i];
    }
    lip[N] = x + li[N-1];

    long long ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 2; j < N; j++) {
            int x = lip[j+1] - lip[i];
            if(x<0) x = x * -1;
            dbg << i << " " << j << " " << x << " " << (j-i+1) << endl;
            if(((j-i+1)-x) <= 2) ans++;
        }
    }

    cout << ans;
	return 0;
}

