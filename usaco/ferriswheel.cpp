#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x; cin >> n >> x;
	vector<int> ps;
	for(int i = 0; i < n; i++) {
		int p; cin >> p;
		ps.push_back(p);
	}
	sort(ps.begin(), ps.end());

	int l = 0, r = n-1, ans = 0;
	while(l < r) {
		//cout << l << " " << r << "\n";
		if(ps[l]+ps[r] <= x) {
			ans++;
			l++; r--;
		} else {
			ans++;
			r--;
		}
	}
	if(l == r) ans++;

	cout << ans << "\n";

	return 0;
}
