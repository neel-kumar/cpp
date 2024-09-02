#include <bits/stdc++.h>
using namespace std;

signed main() {
	long long n, m; cin >> n >> m;
	vector<long long> a(n);
	for(long long i = 0; i < n; i++) cin >> a[i];

	if(n <= m) {
		long long ans = 1;
		for(long long i = 0; i < n; i++) for(long long j = i+1; j < n; j++) ans = (ans*abs(a[i]-a[j]))%m;
		cout << ans << endl;
	} else {
		bool php[m];
		long long ans = 1;
		for(long long i = 0; i < n; i++) {
			for(long long j = i+1; j < n; j++) {
				long long x = abs(a[i]-a[j]) %m;
				if(php[x]) {
					cout << "0";
					return 0;
				}
				php[x] = true;
			}
		}
	}

	return 0;
}
