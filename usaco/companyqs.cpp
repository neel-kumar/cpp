#include <bits/stdc++.h>

using namespace std;

int n, q;
int tr[200005];
int qs[200005][18];

int main() {
    tr[1] = -1;
    cin >> n >> q;
    for(int i = 2; i <= n; i++) {
        cin >> tr[i];
    }
    qs[1][0] = -1;
    for(int i = 1; i < 18; i++) {
        qs[1][i] = -1;
    }
    for(int i = 2; i <= n; i++) {
        qs[i][0] = tr[i];
        bool is1 = false;
        for(int j = 1; j < 18; j++) {
            if(is1) qs[i][j] = -1;
            else {
                qs[i][j] = qs[qs[i][j-1]][j-1];
                if(qs[i][j] == -1) is1 = true;
            }
        }
    }
    for(int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        int ans = x;
        for(int j = 0; j < 19; j++) {
            //cout << ans << " ";
            if(ans == -1) {
                cout << "-1\n";
                break;
            }
            if(k&(1<<j)) {
                ans = qs[ans][j];
            }
        }
        if(ans != -1) cout << ans << "\n";
    }

    return 0;
}
