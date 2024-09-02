#include <bits/stdc++.h>
using namespace std;

signed main() {
	long long n, t; cin >> n >> t;
	long long a[n]; for(long long i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	vector<pair<long long, long long>> freq;
	for(long long i = 0; i < n; i++) {
		freq.push_back(make_pair(0, 1));
		for(long long j = i+1; j < min(n, i+31); j++) {
			freq.push_back(make_pair(a[j]-a[i], 1<<(j-i-1)));
		}
	}
	sort(freq.begin(), freq.end());

	vector<long long> ps; long long curr = 0;
	for(pair<long long, long long> i : freq) {
		curr += i.second;
		ps.push_back(curr);
	}

	while(t--) {
		long long k; cin >> k;
		long long l = 0, r = freq.size();
		while(l < r) {
			long long mid = (l+r)/2;
			if(ps[mid] >= k) r = mid;
			else l = mid+1;
		}
		cout << freq[l].first << endl;
	}
	return 0;
}
