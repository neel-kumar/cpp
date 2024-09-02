#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

long long m, s;

int main() {
    cin >> m >> s;
    vector<int> g;
    long long tmps = s;
    long long tmpm = m;
    while(tmpm > 0) {
        if(tmps < 9) {
           g.push_back(tmps);
           tmps = 0;
        } else {
           tmps -= 9;
           g.push_back(9);
        }
        tmpm--;
    }

    vector<int> sm;
    sm.push_back(1);
    for(int i = 1; i < m; i++) {
        sm.push_back(0);
    }
    tmps = s-1;
    int place = m-1;
    while(tmps > 0) {
        if(tmps < 9) {
           sm[place] += tmps;
           tmps = 0;
        } else {
           sm[place] += 9;
           tmps -= 9;
        }
        place--;
    }
    int tg = 0, ts = 0;
    for(int i = 0; i < m; i++) {
        tg += g[i];
        ts += g[i];
    }
    cout << tg << " " << ts << "\n";
    if(tg != s || ts != s) {
        cout << "-1 -1";
        return 0;
    }

    for(int i : sm) {
        cout << i;
    }
    cout << " ";
    for(int i : g) {
        cout << i;
    }
    return 0;
}
