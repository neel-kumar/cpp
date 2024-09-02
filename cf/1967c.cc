#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve2() {
	int n, k; cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		a[i] = x;
	}

	sort(a, a+n);

	// binary search to find greatest
	int l = 0, r = (int)1e13;
	while(l < r) {
		int mid = (l+r+1)/2;
		int tk = k;
		for(int i = 0; i < n && tk >= 0; i++) {
			if(a[i] >= mid) break;
			tk -= mid-a[i];
		}

		if(tk >= 0)
			l = mid;
		else
			r = mid-1;
	}

	int tk = k;
	for(int i = 0; i < n && tk > 0; i++) {
		if(a[i] > l) break;
		else {
			tk -= l-a[i];
			a[i] = l;
		}
	}
	for(int i = n-1; i >= 0 && tk > 0; i--) {
		if(a[i] == l) {
			tk--;
			a[i]++;
		}
	}

	int xtra = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] > l)
			xtra++;
	}
	/* cout << l << " " << xtra << endl; */
	cout << l*n-n+1+xtra << endl;
}

void solve() {
	int n, k; cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		a[i] = x;
	}

	sort(a, a+n);

	// binary search to find greatest
	int l = 0, r = (int)1e13;
	while(l < r) {
		int mid = (l+r+1)/2;
		int tk = k;
		for(int i = 0; i < n && tk >= 0; i++) {
			if(a[i] >= mid) break;
			tk -= mid-a[i];
		}

	int tk = k;
	for(int i = 0; i < n && tk > 0; i++) {
		if(a[i] > l) break;
		else {
			tk -= l-a[i];
			a[i] = l;
		}
	}
	for(int i = n-1; i >= 0 && tk > 0; i--) {
		if(a[i] == l) {
			tk--;
			a[i]++;
		}
	}

	int xtra = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] > l)
			xtra++;
	}
	/* cout << l << " " << xtra << endl; */
	cout << l*n-n+1+xtra << endl;

	if(tk >= 0)
		l = mid;
	else
		r = mid-1;
	}

}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
