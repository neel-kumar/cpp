#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	map<char, vector<int>> ps;
	string alph = "abcdefghijklmnopqrstuvwxyz";
	for(char c : alph) {
		ps[c].push_back(0);
		for(int i = 0; i < (int)s.size(); i++) {
			ps[c].push_back(ps[c][i]);
			if(s[i] == c) ps[c][i+1]++;
		}
	}

	int q; cin >> q;
	while(q--) {
		int x,y, i,j; cin >> x >> y >> i >> j;
		x--; y--; i--; j--;
		bool works = true;
		for(char c : alph) {
			int xy = ps[c][y+1]-ps[c][x];
			int ij = ps[c][j+1]-ps[c][i];
			//cout << c << " " << ps[c][y+1] << " " << ps[c][x] << endl;
			if(xy != ij) {
				cout << "NO\n";
				works = false;
				break;
			}
		}
		if(works) cout << "YES\n";
	}
	return 0;
}
