#include <bits/stdc++.h>

using namespace std;
using lb = long double;
using ll = long long;

int main() {
    int n, m; cin >> n >> m;
    map<int, int> npos, posn;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        npos[x] = i;
        posn[i+1] = x;
    }

    int ans = 0;
    map<int, int> sps;
    for(int i = 1; i < n; i++) {
        if(npos[i] > npos[i+1])
            ans++;
        sps[i] = npos[i] > npos[i+1];
    }

        for(int j = 1; j <= n; j++) cout << npos[j] << "\n";
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        int apos = npos[posn[a]];
        npos[posn[a]] = b;
        npos[posn[b]] = apos;
        if(a+1 <= n) ans += (npos[posn[a]] > npos[posn[a]+1]) - sps[posn[a]];
        if(a-1 > 0) ans += (npos[posn[a]-1] > npos[posn[a]]) - sps[posn[a]-1];
        if(b+1 <= n) ans += (npos[posn[b]] > npos[posn[b]+1]) - sps[posn[b]];
        if(b-1 > 0) ans += (npos[posn[b]-1] > npos[posn[b]]) - sps[posn[b]-1];

        sps[posn[a]] = npos[posn[a]] > npos[posn[a]+1];
        sps[posn[a]-1] = npos[posn[a]-1] > npos[posn[a]];
        sps[posn[b]] = npos[posn[b]] > npos[posn[b]+1];
        sps[posn[b]-1] = npos[posn[b]-1] > npos[posn[b]];
        for(int j = 1; j <= n; j++) cout << npos[j] << " ";
        cout << ans << "\n";
    }

    return 0;
}
