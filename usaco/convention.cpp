#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

bool valid(int mid, int M, int C, vector<int>& at) {
    int tmpC = C-1;
    int tmp1st = at[0];
    int ats = at.size();
    for(int i = 1; i < ats; i++) {
        if(at[i]-tmp1st > mid || tmpC <= 0) {
            tmp1st = at[i];
            tmpC = C-1;
            M--;
        } else {
            tmpC--;
        }

        if(M <= 0) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    
    int N, M, C;
    cin >> N >> M >> C;
    vector<int> at;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        at.push_back(x);
    }
    sort(at.begin(), at.end());

    int l = 0, r = at.back()-at.front(), ans;
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(valid(mid, M, C, at)) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout << ans;

    return 0;
}
