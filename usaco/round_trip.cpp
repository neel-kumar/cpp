// A C++ Program to detect
// cycle in an undirected graph
#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
using ld = long double;
using ll = long long;


const ll SIZE = 200001;

ll x, y;
vector<ll> adj[SIZE];
ll ans[SIZE];
stack<ll> path;

void addEdge(ll v, ll w)
{
    assert(v >= 0 && v < SIZE);
    assert(w >= 0 && w < SIZE);

    adj[v].push_back(w);
    adj[w].push_back(v);
}

void dfs(ll n, ll p, const ll l) {
    path.push(n);
    if(ans[n] != 0) {
        if(l-ans[n] >= 3) {
            // prll/find final output
            cout << l-ans[n]+1 << "\n";
            cout << n+1 << " ";
            assert(!path.empty());
            assert(path.size() >= l-ans[n]+1);

            path.pop();
            assert(!path.empty());
            while(path.top() != n) {
                assert(!path.empty());
                cout << path.top()+1 << " ";
                path.pop();
                assert(!path.empty());
            }
            cout << n+1 << endl;
            exit(0);
        }
        assert(!path.empty());
        path.pop();
        return;
    }
    ans[n] = l;
    for(ll i : adj[n]) {
        if(i == p)
            continue;
        dfs(i, n, l+1);
        assert(!path.empty());
        path.pop();
    }
}

// Driver program to test above functions
int main()
{
    cin >> x >> y;
    for(ll i = 0; i < y; i++) {
        ll a, b; cin >> a >> b;
        addEdge(a-1, b-1);
    }

    for(ll i = 0; i < x; i++) {
        if(ans[i] == 0)
            dfs(i, -1, 1);
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
