#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n, x; cin >> n >> x;
		int a[n], b[n], c[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n; i++) cin >> b[i];
		for(int i = 0; i < n; i++) cin >> c[i];

		int curr = 0;
		for(int i = 0; i < n && curr != x; i++) {
			if((x | a[i]) != x) break;
			curr |= a[i];
		}
		for(int i = 0; i < n && curr != x; i++) {
			if((x | b[i]) != x) break;
			curr |= b[i];
		}
		for(int i = 0; i < n && curr != x; i++) {
			if((x | c[i]) != x) break;
			curr |= c[i];
		}

		if(curr == x) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}
