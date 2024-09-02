#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a[2];

int st(vector<int> v) {
	map<int,int> f;
	int ret = 0;
	stack<int> s;
	for(int i : v) {
		if(f.count(i) == 0) {
			f[i] = 1;
			s.push(i);
			continue;
		}

		if(f[i]%2 == 0) {
			f[i]++;
			s.push(i);
			continue;
		}

		while(s.top() < i && !s.empty()) {
			ret = max(ret, s.top());
			s.pop();
		}
		if(s.top() != i) ret = max(ret, i);
		s.push(i);
	}
	return ret;
}

int main() {
	cin >> n;
	a[0].resize(n);
	a[1].resize(n);
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	// stack thing
	int ans = max(st(a[0]), st(a[1]));

	// check if theres anything in different rows
	set<int> s[2];
	for(int j = 0; j < 2; j++) {
		for(int i : a[j]) {
			if(s[j].count(i)) s[j].erase(s[j].find(i));
			else s[j].insert(i);
		}
	}

	for(int i : s[0]) {
		if(s[1].count(i) == 0) {
			cout << "-1\n";
			return 0;
		} else {
			ans = max(ans, i);
		}
	}
	cout << ans << '\n';
}
