#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int a, b, n; cin >> a >> b >> n;
		int count = 0;
		while(max(a, b) <= n) {
			count++;
			int c = a+b;
			if(a<b) a = c;
			else b = c;
		}
		cout << count << endl;
	}
	return 0;
}
