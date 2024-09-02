#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
using ld = long double;
using ll = long long;

int N, Q, g[1501][1501], memo[1501][1501];
int ans;

int f() {
    int ret = 0;
    for(int i = N-1; i >= 0; i--) {
        for(int j = i; j >= 0; j--) {
            int x = i;
            int y = j;
            if(g[i][j] == 0)
                y++;
            else
                x++;
            memo[i][j] = memo[x][y];
            ret += memo[i][j];

            if(i != j) {
                x = j;
                y = i;
                if(g[j][i] == 0)
                    y++;
                else
                    x++;
                memo[j][i] = memo[x][y];
                ret += memo[j][i];
            }
        }
    }
    return ret;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            char c; cin >> c;
            if(c == 'D')
                g[i][j] = 1;
        }
        cin >> g[i][N];
        memo[i][N] = g[i][N];
    }
    for(int i = 0; i < N; i++) {
        cin >> g[N][i];
        memo[N][i] = g[N][i];
    }

    cin >> Q;
    ans = f();
    cout << ans << endl;
    for(int i = 0; i < Q; i++) {
        int x, y; cin >> x >> y;
        x--;
        y--;
        if(g[x][y] == 0) {
            g[x][y] = 1;
            f2(x, y, memo[x+1][y]);
        } else {
            g[x][y] = 0;
            f2(x, y, memo[x][y+1]);
        }
        cout << ans << endl;
    }

    return 0;
}
