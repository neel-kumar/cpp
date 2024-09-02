#include <bits/stdc++.h>

using namespace std;

int main() {
	string n, m; cin >> n >> m;
	const int P = 31;
	const int MOD = 1e9 + 7;

	// Calculate hash of m
	int mhash = 0;
	for(int i = 0; i < (int)m.size(); i++) {
		mhash = (((long long)P * mhash) % MOD + int(m[i])-'a'+1) % MOD;
	}

	vector<int> nhash, ppow;
	nhash.push_back(0);
	ppow.push_back(1);

	string ans = "";

	for(int i = 0; i < (int)n.size(); i++) {
		ans += n[i];
		ppow.push_back(((long long)ppow.back() * P) % MOD);
		nhash.push_back((((long long)P * nhash.back()) % MOD + int(n[i])-'a'+1) % MOD);

		if(ans.size() >= m.size()) {
			int h = (MOD + nhash.back() - ((long long)nhash[nhash.size() - 1 - m.size()] * ppow[m.size()]) % MOD ) % MOD;

			assert(h >= 0);

			if(h == mhash && ans.substr(ans.size() - m.size()) == m) {
				ans.resize(ans.size() - m.size());
				nhash.resize(nhash.size() - m.size());
				ppow.resize(ppow.size() - m.size());
			}
		}
	}
	cout << ans << endl;
	return 0;
}
