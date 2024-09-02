#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll P = 69420;
const ll M = 1e9 + 9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	int n = s.length();

	vector<ll> base_pow(n);
	base_pow[0] = 1;
	for (int i = 1; i < n; i++) { base_pow[i] = base_pow[i - 1] * P % M; }

	vector<ll> pref(n + 1);
	for (int i = 1; i <= n; i++) { pref[i] = (pref[i - 1] * P + s[i - 1]) % M; }

	auto get_hash = [&](int l, int r) -> ll {
		ll h = pref[r + 1] - (base_pow[r - l + 1] * pref[l] % M) % M;
		return h < 0 ? h + M : h;
	};

	for(int i = 1; i <= (int)s.size(); i++) {
		int si = 0;
		bool works = true;
		while(si < (int)s.size() && works) {
			int len = min(i, n - si - 1);
			if(get_hash(0, len) != get_hash(si, si + len)) {
				works = false;
			} else {
				si += i;
			}
		}
		if(works)
			cout << i << " ";
	}

	return 0;
}
