#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int x, c = 1; cin >> x;
	n--;
	while(n--) {
		int a; cin >> a;
		if(c <= 0) x = a, c = 0;
		c += (x==a)?1:-1;
	}
	cout << x << endl;
}
