#include <bits/stdc++.h>
using namespace std;

int main() {
	int k, m; cin >> k >> m;
	string s; cin >> s;
	int n; cin >> n;
	vector<array<int, 3>> op(n);
	for(int i = 0; i < n; i++) {
		cin >> op[i][0] >> op[i][1] >> op[i][2];
	}

	for(int i = 0; i < k; i++) {
		int pos = i;
		for(int j = n-1; j >= 0; j--) {
			int l = op[j][2], r = l +(op[j][1]-op[j][0]);
			if(op[j][2] > pos) continue;
			if(pos >= l && pos < r) {
				pos = op[j][0] + (pos-l);
			} else {
				pos -= r-l;
			}
		}
		cout << s[pos];
	}
	cout << endl;
}
