#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long arr[2000001];

bool check(long long med) {
	long long tempk = k;
	for(long long i = n/2; i < n; i++) {
		if(arr[i] >= med) break;
		tempk -= (med-arr[i]);
		if(tempk < 0) return false;
	}
	if(tempk < 0) return false;
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for(long long i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr+n);

	long long l = 1, r = 2*(1e9);
	while(l < r) {
		long long mid = (l+r+1)/2;
		if(check(mid)) l = mid;
		else r = mid-1;
	}
	cout << r << endl;
	return 0;
}
