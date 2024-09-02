// A C++ Program to detect
// cycle in an undirected graph
#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

const int SIZE = 100001;

int x, y;
vector<int> adj[SIZE];
bool vis[SIZE];
int ans[SIZE];

void addEdge(int v, int w)
{
    assert(v >= 0 && v < SIZE);
    assert(w >= 0 && w < SIZE);

	adj[v].push_back(w);
	adj[w].push_back(v);
}

// cycles must be odd for IMPOSSIBLE
bool has_cycles(int n, int p) {
    assert(n >= 0 && n < SIZE);
    vis[n] = true;

    for(int i : adj[n]) {
        assert(i >= 0 && i < SIZE);
        if(p == i)
            continue;
        else if(vis[i]) {
            return true;
        } else {
            bool c = has_cycles(i, n);
            if(c) return true;
        }
    }
    return false;
}

void dfs(int n, int p, const int l) {
    if(ans[n] != 0) {
        if(l%2 != ans[n] %2) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
        return;
    } else if(l%2 == 0)
        ans[n] = 2;
    else
        ans[n] = 1;

    for(int i : adj[n]) {
        if(i == p)
            continue;
        dfs(i, n, l+1);
    }
}

// Driver program to test above functions
int main()
{
    cin >> x >> y;
    for(int i = 0; i < y; i++) {
        int a, b; cin >> a >> b;
        addEdge(a-1, b-1);
    }

    for(int i = 0; i < x; i++) {
        if(ans[i] == 0)
            dfs(i, -1, 0);
    }

    for(int i = 0; i < x; i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

	return 0;
}
