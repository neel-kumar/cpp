#include <bits/stdc++.h>
using namespace std;

int ps[26];
int q;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int q; cin >> q;
	int l = -1;
	int cnt = 0;
	bool d = true;

	// query trav
	while(q--) {
		string t; cin >> t;
		int p; cin >> p;

		// update everything
		int upd = (p-cnt);
		int perl = (int) upd/26;
		for(int i = 0; i < 26; i++) ps[i] += perl;
		cnt += perl*26;
		for(cnt; cnt < p; cnt++) {
			if(d) l++;
			else l--;
			l = l%26;
			if(l < 0) l = 25;
			ps[l]++;
			//cout << "CHAR " << (char)('a'+l) << endl;
		}

		if(t == "UPIT") {
			char c; cin >> c;
			cout << ps[c-'a'] << endl;
		} else {
			d = !d;
		}
	}
}
