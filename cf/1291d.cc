#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	string s; cin >> s;
	int ps[26][s.size()+1];
	for(int i = 0; i < 26; i++) {
		ps[i][0] = 0;
		for(int j = 0; j < s.size(); j++) {
			ps[i][j+1] = ps[i][j] + (s[j] == 'a'+i);
		}
	}
	int q; cin >> q;
	while(q--) {
		int l, r; cin >> l >> r;
		l--; r--;
		int uniq = 0;
		for(int i = 0; i < 26; i++) {
			uniq += ps[i][r+1]-ps[i][l] > 0;
		}
		cout << ((s[l] != s[r] || uniq > 2 || l == r)?"Yes":"No") << endl;
	}
}
