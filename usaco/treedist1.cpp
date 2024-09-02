#include <bits/stdc++.h>
#include <utility>

using namespace std;

int n;
vector<int> g[200001];
int ans = 0;

int findf(int r) {
    //find farthest
    queue<pair<int, int>> q;
    q.push(make_pair(r, -1));
    bool v[100001];
    int f = 0;
    while(!q.empty()) {
        pair<int, int> n = q.front();
        if(!v[n.first]) {
            q.pop();
            v[n.first] = true;
            f = n.first;
            for(int i : g[n.first]) {
                if(i == n.second) continue;
                q.push(make_pair(i, n.first));
            }
        }
    }
    return f;
}

pair<int, int> finddi(int r) {
    int x = findf(r);
    int y = findf(x);
    return make_pair(x, y);
}

void solve(int r) {
    pair<int, int> de = finddi(1);

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
    solve(1);
    return 0;
}
