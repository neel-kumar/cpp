#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n+2);
	for(int i = 1; i <= n; i++) cin >> a[i];
	a[0] = 1e9; a[n+1] = 1e9;

	int r[n+1], l[n+1];
	stack<int> s;
	s.push(0);
	for(int i = 1; i <= n; i++) {
		while(a[s.top()] < a[i]) {
			l[s.top()] = i-1;
			s.pop();
		}
		r[i] = s.top()+1;
		s.push(i);
	}
	while(!s.empty()) {
		l[s.top()] = n;
		s.pop();
	}

	for(int i = 1; i <= n; i++) {
		cout << r[i] << " " << l[i] << endl;
	}
}
