#include <bits/stdc++.h>

using namespace std;

//variables used for the current problem
int n,m; multiset<int> tickets;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0;i<n;++i) {
		int h; cin >> h; tickets.insert(h);
	}
	for (int i=0;i<m;++i) {
		int t; cin >> t;
		auto it = tickets.upper_bound(t);
		if (it==tickets.begin()) {
			cout << -1 << "\n";
		} else {
			cout << *(--it) << "\n";
			tickets.erase(it);
		}
	}
	return 0;
}
