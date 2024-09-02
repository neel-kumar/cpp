#include <set>
#include <map>
#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int>> r2l[101][101];
// set<pair<int, int>> lo, v;
// bool ar[101][101];

char vs[101][101];
char l[101][101];

void ff(int i, int j);

void process(int i, int j) {
    vector<pair<int, int>> nl;

    for(auto p: r2l[i][j]) {
        if(l[p.first][p.second] == 0) {
            // cout << "Lighting room : " << p.first << ", " << p.second << endl;
            l[p.first][p.second] = 1;
            nl.push_back(make_pair(p.first, p.second));
        }
    }

    for(auto p: nl) {
        if(vs[p.first][p.second] == 1) {
            vs[p.first][p.second] = 0;
            ff(p.first, p.second);
        }
    }
}

void ff(int i, int j) {
    if(i <= 0 || i > N || j <= 0 || j > N) {
    } else if(vs[i][j] == 0 && l[i][j] == 1) {
        vs[i][j] = 1;

        process(i, j);

        ff(i, j-1);
        ff(i, j+1);
        ff(i-1, j);
        ff(i+1, j);
    }
}

int main() {
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int xr, yr, xl, yl;
        cin >> xr >> yr >> xl >> yl;
        r2l[xr][yr].push_back(make_pair(xl, yl));
    }
/*
    ar[1][1] = true;
    lo.insert(make_pair(1, 1));
    while(lo.size() > 0) {
        pair<int, int> nv;
        for(auto i : lo) {
            if(ar[i.first][i.second]) {
                nv = i;
                lo.erase(i);
                ar[i.first][i.second] = false;
                v.insert(i);
                break;
            }
        }
        if(nv.first >= 1 && nv.first <= N && nv.second >= 1 && nv.second <= N) {
            ar[nv.first-1][nv.second] = true;
            ar[nv.first+1][nv.second] = true;
            ar[nv.first][nv.second+1] = true;
            ar[nv.first][nv.second-1] = true;
            for(auto i : r2l[nv.first][nv.second]) {
                if(v.count(i) == 0) {
                    lo.insert(i);
                }
            }
        }
    }

    cout << v.size() + lo.size();
    */

    l[1][1] = 1;
    ff(1, 1);

    int nl = 0;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(l[i][j] == 1) nl++;
        }
    }

    cout << nl;

    return 0;
}
