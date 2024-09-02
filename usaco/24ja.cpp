/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") */
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
using ld = long double;
#define f first
#define s second

void solve() {
	int n,q,c;
	cin >> n >> q >> c;
	int a[n];
	pi b[q];
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<q;i++)
		cin >> b[i].f >> b[i].s;


	for(int i=0; i<n; i++) {
		if(a[i]) continue;
		while(a[i] <= c) {
			a[i]++;
			bool works=true;
			for(pi j : b) {
				// check
				if(j.f <= i && i != j.s-1) continue;
				if(a[j.s-1] == 0) continue;
				int mx=0;
				for(int k=0;k<j.f;k++) {
					mx=max(mx,a[k]);
					if(a[k]==0) mx=c;
				}
				for(int k=j.f;k<j.s-1;k++) {
					if(a[k] > mx) {
						works=false;
						break;
					}
				}
				if(!works) break;
				if(a[j.s-1] <= mx && a[j.s-1] != 0) {
					works=false;
					break;
				}
			}
			/* for(int i=0;i<n;i++) */
			/* 	cout << a[i] << ' '; */
			/* cout << endl; */
			if(works) break;
		}
		if(a[i] > c) {
			cout << "-1\n";
			return;
		}
	}

	for(int i=0;i<n;i++) {
		if(a[i]) cout << a[i];
		else cout << "1";
		if(i!=n-1) cout << ' ';
	}
	cout << endl;
}

signed main() {
	/* ios_base::sync_with_stdio(false); cin.tie(NULL); */

	int t;cin>>t;
	while(t--) solve();
}
