#include <bits/stdc++.h>

using namespace std;

int N;
bool h[1000][1000];
bool r[1000];
bool c[1000];

int main() {
    freopen("leftout.in", "r", stdin);
    freopen("leftout.out","w",stdout);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            char x;
            cin >> x;
            h[i][j] = x=='R';
        }
    }
    r[0] = false;
    for(int i = 0; i < N; i++) {
        if(!h[0][i]) c[i] = true;
    }

    for(int i = 1; i < N; i++) {
        int x = 0;
        for(int j = 0; j < N; j++) {
            if(h[i][j] ^ c[j]) x--;
            else x++;
        }
        if(x > 0) r[i] = true;
        else r[i] = false;
    }
/*
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(h[i][j] ^ r[i] ^ c[j]) cout << 'R';
            else cout << 'L';
        }
        cout << "\n";
    }
*/
    int x = 0;
    pair<int, int> ans;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!h[i][j] ^ c[j] ^ r[i]) {
                x++;
                ans.first = i;
                ans.second = j;
            }
        }
    }
    if(x == 1) {
        cout << ans.first+1 << " " << ans.second+1;
        return 0;
    }

    x = 0;
    bool oneans = false;
    for(int j = 0; j < N; j++) {
        x = 0;
        for(int i = 1; i < N; i++) {
            if(!h[i][j] ^ c[j] ^ r[i]) x++;
        }
        if((x != N-1 && x > 0) || (x == N-1 && oneans)) {
            cout << -1;
            return 0;
        }
        if(x == N-1 && !oneans) {
            ans.first = 0;
            ans.second = j;
            oneans = true;
        }
    }
    if(oneans) cout << "1 " << ans.second+1;
    else cout << -1;

    return 0;
}
