#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int f(int k, vector<int>& dt) {
    vector<int> ans;
    int dts = dt.size();
    for(int i = 0; i < dts; i++) {
        if(i < k) {
            ans.push_back(dt.at(i));
        } else {
            int m = 0, anss = ans.size();
            for(int j = 1; j < anss; j++) {
                if(ans.at(j) < ans.at(m)) {
                    m = j;
                }
            }
            ans.at(m) += dt.at(i);
        }
    }
    int r = 0;
    for(int i : ans) {
        r = max(r, i);
    }
    return r;
}


int main() {
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    int N, Tm;
    cin >> N >> Tm;
    vector<int> dt;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        dt.push_back(x);
    }

    int l = 0, r = N, ans = 0;
    while (l <= r) {
        int mid = l + (r-l)/2;
        //cout << f(mid, dt) << " " << mid << endl;
        if(f(mid, dt) <= Tm) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout << ans;
    return 0;
}
