#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n, m; cin >> n >> m;
	int s[n]; for(int i = 0; i < n; i++) cin >> s[i];

	for(int i = 0; i < n-1; i++) {
		s[i+1] = max(s[i+1], s[i]-m);
	}
	for(int i = n-1; i >= 0; i--) {
		s[i-1] = max(s[i-1], s[i]-m);
	}

	for(int i = 0; i < n; i++) cout << s[i] << ' ';
	cout << endl;
}
