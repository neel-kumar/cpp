#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	int a[n];
	map<int,int> lst;
	set<int> ct;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		ct.insert(a[i]);
		lst[a[i]] = i;
	}

	set<int> s;
	map<int,int> cnt;
	set<int> taken;
	int l = 0, r = 0;
	cout << ct.size() << endl;
	for(int j=0; j<ct.size(); j++) {
		while(r < n && (lst[a[r]] != r || taken.count(a[r]))) {
			if(taken.count(a[r]) == 0) {
				s.insert(a[r]);
				cnt[a[r]]++;
			}
			r++;
		}
		if(taken.count(a[r]) == 0 && r < n) s.insert(a[r]);

		int x;
		if(j%2 == 0) {
			x = *s.rbegin();
			s.erase(--s.end());
		} else {
			x = *s.begin();
			s.erase(s.begin());
		}
		cout << x << ' ';
		taken.insert(x);

		for(; l<=r; l++) {
			if(a[l] == x) {
				l++;
				break;
			}
			cnt[a[l]]--;
			if(cnt[a[l]] == 0 && taken.count(a[l]) == 0) s.erase(s.find(a[l]));
		}
		if(l > r) r=l;
	}
	cout << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
