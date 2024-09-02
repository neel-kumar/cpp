#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

bool valid(int mid, int C, vector<int>& at) {
    int tmp1st = at[0];
    int ats = at.size();
    for(int i = 1; i < ats; i++) {
        if(at[i]-tmp1st > mid*2) {
            tmp1st = at[i];
            C--;
        }

        if(C <= 0) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    
    int N, K;
    cin >> N >> K;
    vector<int> hb;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        hb.push_back(x);
    }
    sort(hb.begin(), hb.end());

    int l = 0, r = hb.back()-hb.front(), ans;
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(valid(mid, K, hb)) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout << ans;

    return 0;
}
