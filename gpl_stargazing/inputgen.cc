#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	for(int i = 1; i <= 15; i++) {
		string fl = (to_string(i) + ".in");
		freopen(fl.c_str(), "w", stdout);
		cout << i << endl;
	}
}
