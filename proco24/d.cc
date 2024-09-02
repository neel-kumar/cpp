#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int k; string s; cin >> k >> s;
	int i = 0;
	while(k > 0 && i < s.size()) {
		char c = s[i];
		int x = min(c-'a', 'z'-c+1);
		if(k >= x) {
			k -= x;
			s[i] = 'a';
			i++;
		} else {
			c -= k;
			s[i] = c;
			break;
		}
	}

	cout << s << endl;
}
