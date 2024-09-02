#include <set>
#include <vector>
#include <map>
#include <iostream>
#include <cstdio>

using namespace std;
vector<int> g[3001];
int N, M;

void dfs(vector<bool>& vis, int r) {
    for(int i : g[r]) {
        if(!vis[i]) {
            vis[i] = true;
            dfs(vis, i);
        }
    }
}

int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> rmo;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        rmo.push_back(x);
    }

    vector<bool> vis;
    for(int i = 0; i <= N; i++) {
        vis.push_back(false);
    }

    int rmos = rmo.size();
    for(int i = 0; i < rmos-1; i++) {
        vector<bool> tvis;
        tvis = vis;
        tvis[rmo[i]] = true;
        dfs(tvis, rmo[i]);

        int tvs = 0;
        for(bool i : tvis) {
            if(i) {
                tvs++;
            }
        }
        if(tvs == N) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        vis[rmo[i]] = true;
    }
    cout << "YES" << endl;

    return 0;
}
