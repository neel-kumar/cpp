#include <bits/stdc++.h>
using namespace std;

signed main() {
	long long n, m;
	cin >> n >> m;
	vector<long long> fir(n/2), sec(n-fir.size());
	for(long long i = 0; i < n/2; i++) cin >> fir[i];
	for(long long i = 0; i < sec.size(); i++) cin >> sec[i];

	long long ans = 0;
	set<long long> subseq1, subseq2;
	for(long long i = 0; i <= (1 << fir.size()); i++) {
		long long sum = 0;
		for(long long j = 0; j < fir.size(); j++) if(i >> j & 1) { assert(j < fir.size()); sum = (fir[j]+sum)%m; }
		subseq1.insert(sum%m);
		ans = max(sum, ans);
	}
	for(long long i = 0; i <= (1 << sec.size()); i++) {
		long long sum = 0;
		for(long long j = 0; j < sec.size(); j++) if(i >> j & 1) { assert(j < sec.size()); sum = (sum+sec[j])%m; }
		ans = max(sum, ans);
		subseq2.insert(sum%m);
	}

	for(long long i : subseq1) {
		auto x = subseq2.upper_bound(m-i-1);
		int y = *subseq2.rbegin();
		if(x == subseq2.begin()) continue;
		else x--;
		ans = max(ans, ((*x)+i)%m);
		//ans = max(ans, (y+i)%m);
	}
	cout << ans << endl;
}
