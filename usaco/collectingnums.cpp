#include <bits/stdc++.h>

using namespace std;
using lb = long double;
using ll = long long;

int main() {
    int n; cin >> n;
    map<int, int> npos;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        npos[x] = i;
    }

    int ans = 1;
    for(int i = 1; i < n; i++)
        if(npos[i] > npos[i+1]) ans++;

    cout << ans << "\n";

    return 0;
}
