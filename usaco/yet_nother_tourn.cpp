#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    int T; cin >> T;
    while(T--) {
        int n, m; cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        auto sa = a;
        sort(sa.begin(), sa.end());
        int i = 0;
        while(i < n && m >= sa[i]) {
            m -= sa[i];
            i++;
        }

        if (i != n && i > 0 && m + sa[i-1] >= a[i])
            i++;

        cout << n-i+1 << "\n";
    }

    return 0;
}

