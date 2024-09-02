#include <bits/stdc++.h>
using namespace std;

int n;
int a[(int)1e5 +1][5];

bool check(int x) {
	set<int> bits;
	for(int i = 0; i < n; i++) {
		int mask = 0;
		for(int d = 0; d < 5; d++) {
			if(a[i][d] >= x) mask = mask^(1<<d);
		}
		bits.insert(mask);
	}
	for(int i : bits) {
		for(int j : bits) {
			for(int k : bits) {
				bool works = true;
				for(int d = 0; d < 5; d++) {
					if ( !(i & (1<<d) || j & (1<<d) || k & (1<<d)) ) works = false;
				}
				if(works) return true;
			}
		}
	}
	return false;
}

signed main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];

	int l = 0, r = 1e9 + 1;
	while(l < r) {
		int mid = (l+r+1)/2;
		if(check(mid)) l = mid;
		else r = mid-1;
	}
	cout << l << endl;
}
