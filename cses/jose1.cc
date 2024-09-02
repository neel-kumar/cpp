#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> jose(int n, vector<int> a) {
	if(n == 1) return {1};
	vector<int> ret, left;
	for(int i=1; i<n; i+=2)
		ret.push_back(a[i]);
	if(n%2 == 1) {
		left.push_back(a[n-1]);
		for(int i=0; i<n-1; i+=2)
			left.push_back(a[i]);
	} else {
		for(int i=0; i<n; i+=2)
			left.push_back(a[i]);
	}

	vector<int> b(left.size());
	iota(b.begin(), b.end(), 1);
	vector<int> v = jose(left.size(), b);

	for(int i : v)
		ret.push_back(left[i-1]);

	return ret;
}

signed main() {
	int n; cin >> n;

	vector<int> a(n);
	iota(a.begin(), a.end(), 1);

	vector<int> ans = jose(n, a);
	for(int i : ans) cout << i << " ";
	cout << endl;
}
