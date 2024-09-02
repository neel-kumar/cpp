#include <bits/stdc++.h>

using namespace std;

#define int long long

int ps[2505][2505];
int n;

bool scmp(pair<int, int> a,pair<int, int> b) {
	return a.second<b.second;
}

int ps2(int a, int b, int c, int d) {
	a++;b++;c++;d++;
	return ps[c][d]-ps[a-1][d]-ps[c][b-1]+ps[a-1][b-1];
}

signed main() {
	cin >> n;
	vector<pair<int, int>> c(n);
	for(int i = 0; i < n; i++) {
		int a,b; cin>>a>>b;
		c[i] = {a,b};
	}
	sort(c.begin(), c.end());
	for(int i = 0; i < n; i++) c[i].first = i+1;
	sort(c.begin(), c.end(), scmp);
	for(int i = 0; i < n; i++) c[i].second = i+1;

	// make ps
	for(pair<int,int> i : c) ps[i.first][i.second] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			ps[i][j] += ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1];

	// fin calc
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			int ix = min(c[i].first, c[j].first)-1;
			int ax = max(c[i].first, c[j].first)-1;
			ans += ps2(0, i, ix, j)*ps2(ax, i, n-1, j);
		}
	}
	cout << ans+1 << endl;
}
