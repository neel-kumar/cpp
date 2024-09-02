#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> g[200001];
int ans = 0;

int solve(int r, int prev) {
    if(g[r].size() < 2 && prev != -1) return 0;
    else {
        vector<int> toleaf;
        toleaf.push_back(-1);
        for(int i : g[r]) {
            if(i == prev) continue;
            toleaf.push_back(solve(i, r));
        }
        sort(toleaf.begin(), toleaf.end());
        ans = max(ans, toleaf[toleaf.size()-1]+toleaf[toleaf.size()-2]+2);
        return toleaf[toleaf.size()-1]+1;
    }
}

int main() {
    cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    solve(1, -1);
    cout << ans;
    return 0;
}
