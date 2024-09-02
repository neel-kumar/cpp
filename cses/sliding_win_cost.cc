#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n, k; cin>>n>>k;
	if(k == 1) {
		for(int i=0; i<n; i++) cout << "0 "; cout << endl;
		return 0;
	}
	int a[n]; for(int i=0; i<n; i++) cin>>a[i];
	multiset<int> l, r;
	int ls = (k/2 + k%2), rs = k-ls, lc = 0, rc = 0;
	for(int i=0; i<ls; i++) {
		l.insert(a[i]);
		lc += a[i];
	}
	for(int i=ls; i<k-1; i++) {
		if((*l.rbegin()) > a[i]) {
			lc += a[i] - (*l.rbegin());
			rc += (*l.rbegin());
			r.insert(*l.rbegin());
			l.insert(a[i]);
			l.erase(--l.end());
		} else {
			rc += a[i];
			r.insert(a[i]);
		}
	}

	for(int i=k-1; i<n; i++) {
		if(i >= k) {
			if(l.count(a[i-k])) {
				l.erase(l.find(a[i-k]));
				lc -= a[i-k];
				if(r.size() > 0 && rs != 0) {
					l.insert(*r.begin());
					lc += (*r.begin());
					rc -= (*r.begin());
					r.erase(r.begin());
				}
			} else {
				r.erase(r.find(a[i-k]));
				rc -= a[i-k];
			}
		}

		if(l.size() == 0 || (*l.rbegin()) > a[i]) {
			l.insert(a[i]);
			lc += a[i];
		} else {
			r.insert(a[i]);
			rc += a[i];
		}

		if(l.size() > ls) {
			/* cout << "HERE" << endl; */
			r.insert(*l.rbegin());
			rc += (*l.rbegin());
			lc -= (*l.rbegin());
			l.erase(--l.end());
		} else if(r.size() > rs) {
			/* cout << "HERE2" << endl; */
			l.insert(*r.begin());
			lc += (*r.begin());
			rc -= (*r.begin());
			r.erase(r.begin());
		}

		int med = (*l.rbegin());
		cout << ( (ls-1)*med - (lc-med) + rc - rs*med ) << ' ';
	}
	cout << endl;
}
