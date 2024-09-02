#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n; cin >> n;
	vector<pair<int,int>> seg;
	set<int> s;
	int l,r;
	for(int i=0; i<n; i++) {
		int a,b; cin>>a>>b;
		seg.push_back({a,i});
		seg.push_back({b,i});
		if(i == 0) {
			l = a;
			r = b;
		}
	}

	int ans = 0;
	sort(seg.begin(), seg.end());
	for(int i=0; i<n; i++) {
		if(s.count(seg[i].second)) {
			s.erase(s.find(seg[i].second));
			if(seg[i].second==0) break;
		}
		if(s.size() == 1 && (*s.begin()).second==0) {
			ans+=seg[i+1].second-seg[i].second;
		}
	}
	cout << ans << endl;
}
