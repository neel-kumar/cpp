#include <bits/stdc++.h>
#include <utility>

using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> cos;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        cos.push_back(make_pair(a, 1));
        cos.push_back(make_pair(b, -1));
    }

    sort(cos.begin(), cos.end());
    int ans = 0, rs = 0;
    for(int i = 0; i < n*2; i++) {
        rs += cos[i].second;
        ans = max(ans, rs);
    }

    cout << ans << "\n";

    return 0;
}
