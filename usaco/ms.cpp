#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool fcomp(vector<int> i, vector<int> j) {
    return i[0] < j[0];
}

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int N, G;
    cin >> N >> G;
    set<int> mb;
    vector<int> cs;
    map<int, int> c2m;
    vector<vector<int>> l;
    for(int i = 0; i < N; i++) {
        int d, c, m;
        cin >> d >> c >> m;
        vector<int> tl;
        tl.push_back(d);
        tl.push_back(c);
        tl.push_back(m);
        mb.insert(c);
        cs.push_back(c);
        c2m[c] = G;
    }

    sort(l.begin(), l.end(), fcomp);

    int nc = 0, ls = l.size();
    for(int i = 0; i < ls; i++) {
        c2m[l[0][1]] += l[0][2];
        set<int> tmb;
        for(int j : cs) {
            

   return 0;
}
