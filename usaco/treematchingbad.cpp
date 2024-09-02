#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> tree[200001];
vector<int> rtree[200001];
set<int> root, rroot;
int n, c = 0;

int solve(int n, vector<int> *tr) {
    if(tr[n].size() == 0) return 0;
    else {
        bool t = false;
        for(int c : tr[n]) if(solve(c, tr) == 0 && !t) t = true;
        if(t) {
            c++;
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        root.insert(i);
        rroot.insert(i);
    }
    for(int i = 1; i < n; i++) {
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        rtree[e].push_back(s);
        root.erase(e);
        rroot.erase(s);
    }
    if(root.size() != 1) {
        auto r = rroot.begin();
        solve(*r, rtree);
        cout << c+1;
    } else {
        auto r = root.begin();
        solve(*r, tree);
        cout << c;
    }

    return 0;
}

