#include <bits/stdc++.h>
using namespace std;

signed main() {
	long long n; cin >> n;
	long long arr[n];
	for(long long i = 0; i < n; i++) cin >> arr[i];

	for(long long i = 0; i <= (1 << n); i++) {
		long long sum = 0;
		for(long long j = 0; j < n; j++) {
			if(i >> j & 1) sum += arr[j];
			else sum -= arr[j];
		}
		if(sum%360 == 0) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
