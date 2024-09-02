#include <bits/stdc++.h>
using namespace std;

string s;
int b[6];

signed main() {
	cin >> s;
	for(char c : s) {
		switch(c) {
			case 'b': b[0]++; break;
			case 'e': b[1]+=b[0]; b[5]+=b[4]; break;
			case 's': b[3]+=b[2]; b[2]+=b[1]; break;
			case 'i': b[4]+=b[3]; break;
		}
		cerr << c << " == " << b[0] << ' ' << b[1] << ' ' << b[2] << ' ' << b[3] << ' ' << b[4] << ' ' << b[5] << endl;
	}
	cout << b[5] << endl;
}
