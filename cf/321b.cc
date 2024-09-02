#include <bits/stdc++.h>
using namespace std;

int f(multiset<int> s, vector<int> a) {
	sort(a.begin(),a.end());
	int ret=0;
	for(int i : a) {
		if(s.size()==0) return ret;
		auto it = --s.end();
		if(*it < i || s.size()==0) return ret;
		ret += *it-i;
		s.erase(it);
	}
	return ret;
}

signed main() {
	int n,m; cin>>n>>m;
	vector<int> atk,def;
	multiset<int> ciel;
	string s; int x;
	for(int i=0;i<n;i++) {
		cin >> s >> x;
		if(s=="ATK") atk.push_back(x);
		else def.push_back(x);
	}
	sort(def.begin(),def.end());
	for(int i=0;i<m;i++) {
		cin>>x;
		ciel.insert(x);
	}

	int ans=f(ciel,atk);
	multiset<int> cleft;
	auto it = ciel.begin();
	for(int i : def) {
		while(it != ciel.end() && i >= *it) {
			cleft.insert(*it);
			it++;
		}
		if(it == ciel.end()) {
			cout << ans << endl;
			return 0;
		}
		it++;
	}
	while(it != ciel.end()) cleft.insert(*(it++));
	sort(atk.rbegin(),atk.rend());
	int a2=0;
	for(int i : atk) {
		if(cleft.lower_bound(i) == cleft.end()) {
			cout << max(a2,ans) << endl;
			return 0;
		}
		a2 += *(cleft.lower_bound(i))-i;
		cleft.erase(cleft.lower_bound(i));
	}
	for(int i : cleft) a2 += i;
	cout << max(ans,a2) << endl;
}
