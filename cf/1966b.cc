#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	char g[n][m]; for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> g[i][j];

	vector<char> cs{'W', 'B'};
	for(char c : cs) {
		int cnt = 0;
		for(int i = 0; i < m; i++) cnt += g[0][i] == c;
		if(cnt == 0) continue;

		cnt = 0;
		for(int i = 0; i < m; i++) cnt += g[n-1][i] == c;
		if(cnt == 0) continue;

		cnt = 0;
		for(int i = 0; i < n; i++) cnt += g[i][0] == c;
		if(cnt == 0) continue;

		cnt = 0;
		for(int i = 0; i < n; i++) cnt += g[i][m-1] == c;
		if(cnt == 0) continue;

		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
