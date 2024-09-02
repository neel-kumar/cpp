#include <bits/stdc++.h>
/* #define int long long */
using namespace std;

void solve() {
	int n; cin >> n;
	vector<array<int,3>> f, b;
	for(int i=0;i<n;i++) {
		int a,x; cin >> a >> x;
		f.push_back({a,x,i});
		b.push_back({x,a,i});
		if(a!=x) {
			f.push_back({x,a,i+n});
			b.push_back({a,x,i+n});
		}
	}
	sort(f.begin(),f.end());
	sort(b.begin(),b.end());

	int pos[2*n]; // f, b
	for(int bi=0,i=0; i<b.size(); i++) {
		pos[b[i][2]]=bi;
		if(i<b.size()-1 && b[i][0]<b[i+1][0]) bi++;
	}

	int ans[2*n]; for(int i=0; i<2*n; i++) ans[i]=-2;
	set<pair<int,int>> s, s2;
	int prev = f[0][0];
	for(array<int,3> i : f) {
		if(i[0] > prev) {
			for(auto i : s2) s.insert(i);
			s2.clear();
			prev = i[0];
		}
		if(s.size()) {
			pair<int,int> p = *s.begin();
			if(p.first < pos[i[2]]) ans[i[2]] = p.second;
		}
		s2.insert({pos[i[2]],i[2]});
	}

	for(int i = 0; i < n; i++) {
		int x = max(ans[i],ans[i+n]);
		if(x>=n) x-=n;
		cout << x+1 << ' ';
	}
	cout << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
