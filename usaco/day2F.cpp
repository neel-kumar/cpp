#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	set<int> occ_char[27];
	string abcs = "abcdefghijklmnopqrstuvwxyz";
	// map<char, int> let2in; ==== char - 'a'
	for(int i = 0; i < (int)s.size(); i++) occ_char[s[i]-'a'].insert(i+1);

	int t; cin >> t;
	while(t--) {
		int q; cin >> q;
		if(q == 1) {
			int pos; char c; cin >> pos >> c;
			occ_char[s[pos-1]-'a'].erase(occ_char[s[pos-1]-'a'].find(pos));
			occ_char[c-'a'].insert(pos);
			s[pos-1] = c;
		} else {
			int l, r; cin >> l >> r;
			int ans = 0;
			for(int i = 0; i <= 27; i++) {
				auto left = occ_char[i].lower_bound(l);
				if(left != occ_char[i].end() && *left <= r) ans++;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
