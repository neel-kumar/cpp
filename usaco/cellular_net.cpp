#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> cities(n);
	set<int> towers;
	for(int i = 0; i < n; i++)
		cin >> cities[i];
	for(int i = 0; i < m; i++) {
		int x; cin >> x;
		towers.insert(x);
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		int x = 2e9 + 1;
		auto low = towers.lower_bound(cities[i]);
		if(low != towers.end())
			x = *low - cities[i];
		if(low != towers.begin()) {
			low--;
			x = min(x, cities[i] - *low);
		}
		ans = max(ans, x);
	}
	cout << ans << endl;
	return 0;
}
