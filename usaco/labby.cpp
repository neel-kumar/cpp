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

int g[1001][1001], n, m;
bool vis[1001][1001];
string ans;

void f(int x, int y, string s) {
    if(x < n && y < m && x > -1 && y > -1) {
        if(vis[x][y] == 0 && g[x][y] != 1) {
            printf("(%d, %d) = ", x, y);
            cout << s << endl;
            vis[x][y] = 1;
            f(x+1, y, s+'R');
            f(x-1, y, s+'L');
            f(x, y+1, s+'U');
            f(x, y-1, s+'D');
        } else if(g[x][y] == 3) {
            ans = s;
        }
    }
}

int main() {
    cin >> n >> m;
    int x, y;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c; cin >> c;
            if(c == '#')
                g[i][j] = 1;
            else if(c == 'A') {
                g[i][j] = 2;
                x = i;
                y = j;
            } else
                g[i][j] = 3;
            if(c == '#')
                vis[i][j] = 1;
        }
    }

    f(x, y, "");
    cout << ans;
 
    return 0;
}
