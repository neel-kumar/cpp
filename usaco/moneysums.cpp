#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

int n;
set<int> ans;

int main() {
    cin >> n;
    ans.insert(0);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        vector<int> mods;
        for(auto j : ans) {
            mods.push_back(j+x);
        }
        for(int j : mods) {
            ans.insert(j);
        }
    }

    cout << ans.size()-1 << "\n";
    for(auto i : ans) {
        if(i == 0) continue;
        else
            cout << i << " ";
    }
    cout << "\n";

    return 0;
}
