#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n; cin >> n;
	int a = 0, b = 1, t;
	for(int i = 0; i < n; i++) {
		t = a+b;
		a = b;
		b = t;
	}
	cout << b << endl;
}
