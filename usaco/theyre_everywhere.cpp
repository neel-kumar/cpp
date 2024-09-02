#include <bits/stdc++.h>

using namespace std;

int n;
string s;
set<char> types;
map<char, int> curr;

int main() {
	cin >> n;
	cin >> s;
	for(char i : s) {
		types.insert(i);
	}

	int l = 0, ans = INT_MAX;
	for(int r = 0; r < s.size(); r++) {
		curr[s[r]]++;
		while(l+1 < r) {
			if(curr[s[l]] > 1) {
				curr[s[l]]--;
				l++;
			} else
				break;
		}
		if(types.size() == curr.size())
			ans = min(ans, r-l+1);
	}
	cout << ans << endl;
	return 0;
}
