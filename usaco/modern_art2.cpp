#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300000;
int N, minc[MAXN], maxc[MAXN];
multiset<pair<int, int>> compressed;
int colors[MAXN];

signed main() {
	// no same paint on either side of 0s
	// check for xyxy
	// SWEEP LINE
	cin >> N;
	fill_n(minc, MAXN, INT_MAX);
	fill_n(maxc, MAXN, INT_MIN);
	for(int i = 0; i < N; i++) {
		int c; cin >> c;
		minc[c] = min(minc[c], i);
		maxc[c] = max(maxc[c], i);
		colors[i] = c;
	}

	vector<int> s;
	int res = 0;
	for(int i = 0; i <= N; i++) {
		int c = colors[i];

		if (i == minc[c]) {
			s.push_back(c);
			res = max(res, (int)s.size());
		}

		if (s[s.size()-1] != c) {
			cout << -1 << "\n";
			return 0;
		}

		if (i == maxc[c]) {
			s.pop_back();
		}
	}
	cout << res << endl;

	return 0;
}
