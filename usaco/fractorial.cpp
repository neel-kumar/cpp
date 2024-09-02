#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int f = 0;
	while(n) {
		int x = 1;
		int cnt = 1;
		while(x*cnt <= n) {
			x *= cnt;
			cnt++;
		}
		f += (n/x) * pow(10, cnt-2);
		n = n%x;
	}
	cout << f << endl;
}

