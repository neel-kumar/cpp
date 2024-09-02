#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> ii;
using ld = long double;
using ll = long long;

unordered_map<int, vi> g;
unordered_map<int, vll> ansg;
int val[200001], n, ans;
bool visited[200001];
stack<int> S;
// vector<vll> ansm;
unordered_map<int, vector<pair<int, ll>>> ansm;
int t2c[200001];

ll f(const int prev, const int b) {
    ll ret = val[b];
    // ll fr = -1;
    for(ll i : g[b]) {
        if(i == prev)
            continue;
        ll fr = f(b, i);
        if(fr == 0)
            ans--;
        else {
            if(fr > 0) {
                ansm[i].push_back(make_pair(b, fr));
                ansg[i].push_back(b);
            } else {
                ansm[b].push_back(make_pair(i, fr*-1));
                ansg[b].push_back(i);
            }
        }
        ret += fr;
    }
    return ret;
}

void topo_sort(int i) {
    visited[i] = true;
    for(int j : ansg[i])
        if(!visited[j])
            topo_sort(j);
    S.push(i);
}

int main() {
    cin >> n;
    ans = n-1;
    ll tot = 0;
    for(ll i = 0; i < n; i++) {
        ll a; cin >> a;
        tot += a;
        val[i+1] = a;
    }
    ll target = tot/n;
    for(ll i = 0; i < n; i++) {
        val[i+1] = val[i+1]-target;
    }

    for(ll i = 0; i < n-1; i++) {
        ll a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    f(-1, 1);
    cout << ans << endl;
    for(int i = 1; i <= n; i++)
        if(visited[i] == false)
            topo_sort(i);

    while (S.empty() == false) {
        for(auto i : ansm[S.top()])
            cout << S.top() << " " << i.first << " " << i.second << "\n";
        S.pop();
    }

    return 0;
}
