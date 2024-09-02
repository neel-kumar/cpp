#include <bits/stdc++.h>
#include <type_traits>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
using ld = long double;
using ll = long long;

int g[1001][1001];
int n, m, ans = 0;
set<pair<int, int>> vis;

void f(int x, int y) {
    vis.insert(make_pair(x, y));
    if(x < n && y < m && x > -1 && y > -1 && g[x][y] != '#')  {
        f(x+1, y);
        f(x-1, y);
        f(x, y+1);
        f(x, y-1);
    }
}

void ff(int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis.count(make_pair(i, j)) != 0)
                continue;
            ans++;
            f(i, j);
        }
    }
}

int main() {


    return 0;
}
