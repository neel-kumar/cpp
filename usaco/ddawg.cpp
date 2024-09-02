#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>
using namespace std;
#define int long long
using i2 = pair<int, int>;
using i3 = tuple<int, int, int>;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
		int mx; cin >> mx;
    vector<int> v;
    for (int i = 1; i <= mx; i++) {
        int j = i, tot = 0;
        while (j) {
            tot += j;
            j /= 10;
        }
        v.push_back(tot);
    }
    sort(v.begin(), v.end());
    int cur = 0, cnt = 0;
		int ans = 0;
    for (int i = 1; i <= mx; i++) {
        int c = i - (upper_bound(v.begin(), v.end(), i) - v.begin());
        if (c == cur) ++cnt;
        else {
					if(cnt != 11)  {
						ans++;
							cout << "HERE ";
					}
						cout << cur << " " << cnt << endl;
            cur = c;
            cnt = 1;
        }
    }
		cout << ans << endl;
    return 0;
}
