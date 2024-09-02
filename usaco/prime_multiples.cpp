#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
	ll n, k; cin >> n >> k;
	ll ks[k];
	for(int i = 0; i < k; i++) cin >> ks[i];
	ll ans = 0;
	for(int i = 1; i < (1<<k); i++) {
		int tmp = i;
		ll multiples = n;
		int index = 0;
		int cnt = 0;
		while(tmp != 0) {
			bool is1 = (tmp & 1);
			if(is1) {
				multiples = multiples/ks[index];
				cnt++;
			}
			tmp >>= 1;
			index++;
		}
		ans += (cnt%2 ? 1 : -1)*multiples;
	}
	cout << ans << endl;
	return 0;
}
