#include <bits/stdc++.h>
#define int long long
using namespace std;

bool check(vector<pair<int,int>> np, vector<int> pos, int ymin) {
	multiset<int> maxsl;
	for(pair<int,int> i : np) {
		maxsl.insert((i.second-ymin)/i.first);
	}
	for(int i : pos) {
		int j = *maxsl.begin(); maxsl.erase(maxsl.begin());
		if(i>j) return false;
	}
	return true;
}

int fmin(vector<pair<int,int>> np, vector<int> pos) {
	sort(pos.begin(),pos.end());

	int miny=INT_MAX; for(auto i : np) miny=min(miny,i.second);
	int maxx=INT_MIN; for(auto i : np) maxx=max(maxx,i.first);
	int lo=miny-maxx*pos[pos.size()-1], hi=miny;
	while(lo<hi) {
		int mid = (lo+hi+1)/2;
		if(check(np,pos,mid)) lo=mid;
		else hi=mid-1;
	}

	return lo;
}

int fmax(vector<pair<int,int>> nn, vector<int> neg) {
	vector<pair<int,int>> np; vector<int> pos;
	for(auto i : nn) np.push_back({i.first,-i.second});
	for(auto i : neg) pos.push_back(-i);
	return -fmin(np,pos);
}

void solve() {
	int n,x1; cin>>n>>x1;
	vector<int> onx1;
	vector<pair<int,int>> nn,np;
	for(int i=0;i<n;i++) {
		int y1,y2,x2; cin>>y1>>y2>>x2;
		onx1.push_back(y1);
		onx1.push_back(y2);
		np.push_back({x2,y1});
		nn.push_back({x2,y2});
	}
	vector<int> neg,pos;
	for(int i=0;i<n*4;i++) {
		int x; cin>>x;
		if(x<0) neg.push_back(x);
		else pos.push_back(x);
	}
	if(min(neg.size(),pos.size()) < n) {
		cout << "-1\n";
		return;
	}

	// gather onx1 into nn/np
	sort(onx1.begin(),onx1.end());
	for(int i : onx1) {
		if(nn.size() < neg.size()) nn.push_back({x1,i});
		else np.push_back({x1,i});
	}
	assert(nn.size() == neg.size()); assert(np.size() == pos.size());
	int fn=fmin(np,pos);
	int fm=fmax(nn,neg);
	cout << fm-fn << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
