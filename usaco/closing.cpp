#include <set>
#include <vector>
#include <map>
#include <iostream>
#include <cstdio>

using namespace std;
vector<int> g[3001];
int N, M;

void dfs(set<int>& vis, int r) {
    for(int i : g[r]) {
        if(vis.count(i) == 0) {
            vis.insert(i);
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

    set<int> vis;
    int rmos = rmo.size();
    for(int i = 0; i < rmos-1; i++) {
        set<int> tvis;
        tvis = vis;
        tvis.insert(rmo[i]);
        dfs(tvis, rmo[i]);
        int tvs = tvis.size();
        if(tvs == N) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        vis.insert(rmo[i]);
    }
    cout << "YES" << endl;

    return 0;
}
