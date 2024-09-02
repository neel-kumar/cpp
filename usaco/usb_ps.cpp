#include <bits/stdc++.h>

using namespace std;

int main() {
	int ab[2], c, n; cin >> ab[0] >> ab[1] >> c >> n;
	vector<pair<int, int>> ports;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		string s; cin >> s;
		ports.push_back(make_pair(x, !(s=="USB")));
	}
	sort(ports.begin(), ports.end());
	long long ans = 0, ansi = 0;
	for(auto x : ports) {
		ansi++;
		if(ab[x.second] > 0) ans += x.first, ab[x.second]--;
		else if(c > 0) ans += x.first, c--;
		else ansi--;
	}
	cout << ansi << " " << ans << endl; 

	return 0;
}
