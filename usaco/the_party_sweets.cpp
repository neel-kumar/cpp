#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, m; cin >> n >> m;
	long long ans = 0;
	vector<long long> b(n), g(m);
	for(long long i = 0; i < n; i++) {
		cin >> b[i];
		ans += b[i]*m;
	}
	for(long long i = 0; i < m; i++)
		cin >> g[i];
	sort(b.begin(), b.end());
	sort(g.begin(), g.end());
	if(g[0] < b[n-1]) {
		cout << "-1\n";
		return 0;
	}
	for(long long i = 1; i < m; i++)
		ans += g[i] - b[n-1];
	if(g[0] != b[n-1])
		ans += g[0] - b[n-2];
	cout << ans << endl;
	return 0;
}
