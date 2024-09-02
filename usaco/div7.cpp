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

#define DEV_ENV

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

int main() {
    io("div7");
    int N;
    cin >> N;
    int cids[50000];
    in(N, 0) {
        int id;
        cin >> id;
        cids[i] = id;
    }

    long long idps[50001];
    long long sum = 0;
    idps[0] = sum;
    map<long long, int> ps;
    in(N, 0) {
        sum += cids[i];
        idps[i+1] = sum;
        ps[sum] = i;
    }
    /*
       int maxl = 0;
       for(int i = 0; i <= N; i++) {
       if((N - i) <= maxl) break;
       for(int j = N-1; j > i; j--) {
       if((j - i + 1) <= maxl) break;
       else if((idps[j+1] - idps[i]) % 7 == 0) {
       maxl = j - i + 1;
       }
       }
       }

       */

    int maxl = 0;
    dbg << N << endl;
    for(int i = N-1; i >= 0; i--) {
        dbg << maxl << endl;
        long long i7 = idps[i]/7;
        if(i <= maxl) break;
        else if(idps[i] % 7 == 0) maxl = i + 1;
        else if(i7 < i) {
            dbg << "i7" << endl;
            for(long long j = 0; j < idps[i]; j = j + 7) {
                if(ps.count(idps[i] - j) != 0) {
                    maxl = i - ps[j] + 1; 
                }

            }
        } else {
            dbg << "normal" << endl;
            for(int j = 0; j < i; j++) {
                if((j - i + 1) <= maxl) break;
                else if((idps[j+1] - idps[i]) % 7 == 0) {
                    maxl = j - i + 1;
                }
            }
        }
    }

    cout << maxl;
    return 0;
}

