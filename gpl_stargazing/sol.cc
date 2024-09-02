#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<string> ans;
	string l, r;
	for (int i = 0; i < (1 << n); i++) {
		l = "", r = "";
		for (int j = 0; j < n; j++) {
			if ((i & (1 << j)) == 0) {
				l += to_string(j+1) + " ";
			} else {
				r += " " + to_string(j+1);
			}
		}
		ans.push_back(l + "sun" + r);
	}

	sort(ans.begin(), ans.end());
	for(string s : ans) cout << s << endl;
}
