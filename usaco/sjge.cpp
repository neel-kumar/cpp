#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
using ll = long long;

int p[500][500];
bool val[500][500];
int N;
ll ans;

ll solve() {
    ll c = 0;

    for(int u = 0; u < N; ++u) {
        vector<bool> all_ones(N, true);
        for(int l = u; l < N; ++l) {
            int nco = 0;
            for(int w = 0; w < N; ++w) {
                all_ones[w] = (all_ones[w] && val[l][w]);
                if(all_ones[w]) {
                    c += ++nco;
                } else {
                    nco = 0;
                }
            }
        }
    }

    return c;
}

int main() {
    // freopen("sjge.in", "r", stdin);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> p[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            val[i][j] = p[i][j] >= 100;
        }
    }

    ans = solve();
    // cout << ans << "\n";

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            val[i][j] = p[i][j] > 100;
        }
    }

    ans -= solve();

    cout << ans << "\n";
    return 0;
}

