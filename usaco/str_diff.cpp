#include <bits/stdc++.h>
using namespace std;

signed main() {
	int n; cin >> n;
	string s; cin >> s;

	int m = 0;
	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < 26; j++) {
			if(i==j) continue;
			int mi=INT_MAX,c=0,mip=0;
			for(char ch : s) {
				int v=0;
				if(ch=='a'+i) {
					c++;
					m=max(m,c-mi);
				} else if(ch=='a'+j) {
					mi = min(mi,mip);
					c--;
					mip = c;
					m=max(m,c-mi);
				}
			}
		}
	}
	cout << m << endl;
}
