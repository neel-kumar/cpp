#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> cos;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        cos.push_back(make_pair(b, a));
    }

    sort(cos.begin(), cos.end());
    int ans = 0, end = 0;
    for(int i = 0; i < n; i++) {
        if(cos[i].second >= end) {
            end = cos[i].first;
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}
