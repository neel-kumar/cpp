#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(int n) {
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

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	for(int i = 1; i <= 15; i++) {
		string fl = (to_string(i) + ".out");
		freopen(fl.c_str(), "w", stdout);
		solve(i);
	}
}
