#include <bits/stdc++.h>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
using ld = long double;
using ll = long long;

int g[1001][1001], n, m, ans = 0;
bool vis[1001][1001];

void f(int x, int y) {
    if(x < n && y < m && x > -1 && y > -1) {
        if(vis[x][y] == 0 && g[x][y] != 1) {
            vis[x][y] = 1;
            f(x+1, y);
            f(x-1, y);
            f(x, y+1);
            f(x, y-1);
        } 
    }
}

void ff(int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] != 0)
                continue;
            ans++;
            f(i, j);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c; cin >> c;
            if(c == '#')
                g[i][j] = 1;
            if(c == '#')
                vis[i][j] = 1;
        }
    }

    ff(n, m);
    cout << ans;
 
    return 0;
}
