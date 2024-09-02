#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	map<int, int> ps; // ps to i
	int curr = 0;
	ps[0] = 0;
	for(int i = 1; i <= n; i++) {
		int x; cin >> x;
		curr += x;
	}

	return 0;
}
