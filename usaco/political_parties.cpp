#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> p[200001];

signed main() {
	int n; cin >> n;
	for(int i = 0; i < 5; i++) {
		int ps; cin >> ps;
		for(int j = 0; j < ps; j++) {
			int a, b; cin >> a >> b;
			a--; b--;
			p[a].push_back(b);
			p[b].push_back(a);
		}
	}

	string ans = ""; for(int i = 0; i < n; i++) ans += "A";
	while(true) {
		int i;
		for(i = 0; i < n; i++) {
			int c = 0;
			for(int j : p[i])
				c += (ans[i] == ans[j]);
			if(c > 2) {
				ans[i] = 'B';
				break;
			}
		}
		if(i == n) break;
	}

	cout << ans << endl;

    return 0;
}
