#include <bits/stdc++.h>
/* #define int long long */
using namespace std;

signed main() {
	#ifndef LJ // g++ -DLJ
	freopen("snowboots.in", "r", stdin); freopen("snowboots.out", "w", stdout);
	#endif

	int n,b; cin>>n>>b;
	vector<pair<int,int>> f(n);
	for(int i=0;i<n;i++) cin>>f[i].first, f[i].second=i;

	f.erase(f.begin()); f.erase(f.begin() + n-1);
	sort(f.begin(), f.end());
	vector<pair<int,int>> v;
	set<int> s;
	multiset<int> gaps;
	int cu = 0;
	s.insert(n-1); s.insert(0); gaps.insert(n-1);
	for(pair<int,int> i : f) {
		if(i.first != cu) {
			v.push_back({cu, *gaps.rbegin()});
			cu = i.first;
		}

		auto it2 = s.upper_bound(i.second);
		auto it = it2; it--;
		gaps.erase(gaps.find(*it2 - *it));
		gaps.insert(i.second-(*it));
		gaps.insert(*it2-i.second);
		s.insert(i.second);
	}
	v.push_back({cu, *gaps.rbegin()});

	int x,y;
	for(int i=0;i<b;i++) {
		cin>>x>>y;
		auto it = lower_bound(v.begin(),v.end(), make_pair(x,INT_MAX)); it--;
		cout<< ((*it).second<=y) <<endl;
	}
}
