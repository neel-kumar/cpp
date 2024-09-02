#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		vector<int> prefix;
		int curr = 0;
		prefix.push_back(0);
		for(int i = 0; i < n; i++) {
			char x; cin >> x;
			int a = x-'0';
			curr += a;
			prefix.push_back(curr);
		}
		map<int, long long> m;
		for(int i = 0; i <= n; i++) {
			m[prefix[i]-i]++;
		}
		long long ans = 0;
		for (const auto &[_, f] : m) {
			ans += (f*(f-1))/2;
		}
		cout << ans << "\n";
	}
	return 0;
}
