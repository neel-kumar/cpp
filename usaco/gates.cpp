#include <iostream>
#include <cstdio>

using namespace std;

int N;
char p[1000];
bool v[2001][2001];

int main() {
    freopen("gates.in", "r", stdin);
    //freopen("gates.out", "w", stdout);
    cin >> N;
    for(int i = 0; i < N; i++) {
        char d;
        cin >> d;
        p[i] = d;
    }

    int x = 1000, y = 1000;
    v[x][y] = true;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(p[i] == 'N') {
            x++;
        } else if(p[i] == 'S') {
            x--;
        } else if(p[i] == 'E') {
            y++;
        } else {
            y--;
        }
        if(v[x][y]) {
            ans++;
        }
        v[x][y] = true;
    }

    cout << ans;

    return 0;
}
