#include <bits/stdc++.h>
using namespace std;

bool nums[200001];
int n;

signed main() {
	cin >> n;
	for(int i = 1; i < n; i++) {
		int x; cin >> x;
		nums[x] = true;
	}
	for(int i = 1; i < n+1; i++) {
		if(!nums[i]) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
