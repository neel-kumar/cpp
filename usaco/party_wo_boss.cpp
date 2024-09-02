#include <bits/stdc++.h>

// #include <set>
// #include <map>
// #include <vector>
// #include <iostream>

using namespace std;

vector<int> Ri;
int N;
map<int, vector<int>> tree;
map<int, int> memo0;
map<int, int> memo1;

int solve(int n, bool in) {
    if(in && memo1[n] != 0)
        return memo1[n];
    else if(!in && memo0[n] != 0)
        return memo0[n];
    else if(tree[n].empty()) {
        if(in)
            return Ri[n-1];
        else
            return 0;
    }
    int ret = 0;
    for(auto i : tree[n]) {
        if(in) {
            ret += solve(i, !in);
        } else {
            ret += max(solve(i, in), solve(i, !in));
        }
    }
    if(in)
        ret += Ri[n-1];
    //printf(" (%d, %d, %d) ", n, in, ret);
    if(in)
        memo1[n] = ret;
    else
        memo0[n] = ret;
    return ret;
}

int main() {
    cin >> N;
    set<int> r;
    for(int i = 1; i <= N; i++) {
        int x; cin >> x;
        Ri.push_back(x);
        r.insert(i);
	}
    
    for(int i = 1; i < N; i++) {
        int x, y; cin >> x >> y;
        tree[y].push_back(x);
        r.erase(x);
	}
    int root = *r.begin();
    cout << max(solve(root, true), solve(root, false));
}

