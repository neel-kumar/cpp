#include <vector>
#include <map>
#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>

using namespace std;

int g[1000][1000];
int totv[1001][1001];
int N;

void ff(int i, int j, pair<int, int>& ans, /*int (*v)[1001][1001],*/ pair<int, int> p) {
    if(i >= 0 && j >= 0 && i < N && j < N && g[i][j] == 1 && totv[i][j] == 0) {
        //(*v)[i][j] = 1;
        totv[i][j] = 1;
        ans.first++;
        ans.second += 2;
        if(make_pair(i+1, j) == p){
            ff(i-1, j, ans, make_pair(i, j));
            ff(i, j+1, ans, make_pair(i, j));
            ff(i, j-1, ans, make_pair(i, j));
        } else if(make_pair(i-1, j) == p){
            ff(i+1, j, ans, make_pair(i, j));
            ff(i, j+1, ans, make_pair(i, j));
            ff(i, j-1, ans, make_pair(i, j));
        } else if(make_pair(i, j+1) == p){
            ff(i+1, j, ans, make_pair(i, j));
            ff(i-1, j, ans, make_pair(i, j));
            ff(i, j-1, ans, make_pair(i, j));
        } else if(make_pair(i, j-1) == p){
            ff(i+1, j, ans, make_pair(i, j));
            ff(i-1, j, ans, make_pair(i, j));
            ff(i, j+1, ans, make_pair(i, j));
        } else {
            ff(i+1, j, ans, make_pair(i, j));
            ff(i-1, j, ans, make_pair(i, j));
            ff(i, j+1, ans, make_pair(i, j));
            ff(i, j-1, ans, make_pair(i, j));
        }
    } else if(i >= 0 && j >= 0 && i < N && j < N && totv[i][j] == 1) {
        ans.second -= 1;
    }
}

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            char x;
            cin >> x;
            if(x == '#') {
                g[i][j] = 1;
            } else {
                g[i][j] = 0;
            }
        }
    }

    pair<int, int> ans;
    ans.first = 0;
    ans.second = INT32_MAX;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(totv[i][j]) {
                continue;
            }
            pair<int, int> bd;
            bd.second = 2;
            bd.first = 0;
            pair<int, int> p;
            p.first = -1;
            p.second = -1;

            //int v[1001][1001];

            //ff(i, j, bd, &v, p);
            ff(i, j, bd, p);
            if(bd.first > ans.first) {
                ans = bd;
            } else if(bd.first == ans.first && bd.second < ans.second) {
                ans = bd;
            }
        }
    }

    cout << ans.first << " " << ans.second;
    return 0;
}
