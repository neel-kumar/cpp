#include <bits/stdc++.h>

using namespace std;

int main() {
	string n, m; cin >> n >> m;
	const int P = 31;
	const int MOD = 1e9 + 7;

	long long mhash= 0;
	long long curr = 0;
	long long ppow = 1;
	for(int i = m.size()-1; i >= 0; i--) {
		ppow = ppow*P %MOD;
		mhash += ppow * (int(m[i])-'a'+1);
		mhash = mhash %MOD;
		curr += ppow * (int(n[i])-'a'+1);
		curr = curr %MOD;
	}

	int ans = (curr == mhash);
	for(int i = m.size(); i < n.size(); i++) {
		curr += (int(n[i])-'a'+1);
		curr -= (ppow * (int(n[i-m.size()])-'a'+1))%MOD;
		curr = MOD + curr;
		curr *= P;
		curr = curr%MOD;
		ans += (curr == mhash);
	}
	cout << ans << endl;
	return 0;
}
