#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
string s;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	cin.ignore();
	getline(cin, s);
	vector<int> v;
	string c = "";
	for(char i : s) {
		if(i == '-' || i == ' ') {
			c += i;
			v.push_back(c.size());
			c = "";
		} else {
			c += i;
		}
	}
	if(c != "") v.push_back(c.size());

	int l = 1, r = s.size();
	while (l < r) {
		int m = (l+r)/2;

		int ln = 1, cur = 0;
		for(int i : v) {
			if(i > m) {
				ln = n+1;
				break;
			} else if(cur+i > m) {
				ln++;
				cur = i;
			} else {
				cur += i;
			}
		}

		if(ln <= n) r = m;
		else l = m+1;
	}
	cout << l << endl;
}
