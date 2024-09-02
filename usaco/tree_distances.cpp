#include <bits/stdc++.h>

using namespace std;

int dist[2][200001], N;
map<int, vector<int>> tree;

int dfs(int n, int l, int i, int p) {
    //printf("DFS(%d, %d, %d, %d) ", n, l, i, tree[n].size());
    dist[i][n] = l;
    if(tree[n].size() <= 1 && p != -1)
        return n;
    int ret = 0, len = 0;
    for(int ch : tree[n]) {
        if(ch == p)
            continue;
        int up = dfs(ch, l+1, i, n);
        if(dist[i][up] >= len) {
            len = dist[i][up];
            ret = up;
        }
    }
    return ret;
}

int main() {
    cin >> N;
    for(int i = 1; i < N; i++) {
        int x, y; cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    int a = dfs(1, 0, 0, -1);
    int b = dfs(a, 0, 0, -1);
    dfs(b, 0, 1, -1);
    for(int i = 1; i <= N; i++) {
        cout << max(dist[0][i], dist[1][i]) << " ";
    }

    return 0;
}
