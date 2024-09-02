#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> a;

int last_true(int lo, int hi, function<bool(int)> f) {
	lo--;
	for (int dif = hi - lo; dif > 0; dif /= 2) {
		while (lo + dif <= hi && f(lo + dif)) { lo += dif; }
	}
	return lo;
}

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	cout << last_true(0, 2e9, [&](int x) {
		long long ret = 0;
		for(int i = (n-1)/2; i < n; i++)
			ret += max(0, x-a[i]);
		return ret <= k;
	});
	return 0;
}
