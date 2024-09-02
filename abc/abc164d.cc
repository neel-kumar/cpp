#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	string s; cin >> s;
	int ps[s.size()+1];
	ps[s.size()] = 0;
	int pot = 1;
	for (int i = s.size()-1; i >= 0; i--) {
		ps[i] = ps[i+1] + (s[i] - '0') * pot;
		pot = (pot * 10) % 2019;
	}

	int c = 0;
	int mod[2019] = {0};
	for(int i = 0; i <= s.size(); i++) {
		int m = ps[i] % 2019;
		c += mod[m];
		mod[m]++;
	}
	cout << c << endl;
}
