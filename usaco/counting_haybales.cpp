#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);

	int n, q;
	cin >> n >> q;
	vector<int> locs(n);
	for(int i = 0; i < n; i++)
		cin >> locs[i];
	sort(locs.begin(), locs.end());
	for(int i = 0; i < q; i++) {
		int s, e; cin >> s >> e;
		cout << upper_bound(locs.begin(), locs.end(), e) - lower_bound(locs.begin(), locs.end(), s) << "\n";
	}
	return 0;
}
