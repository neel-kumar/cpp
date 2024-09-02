#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<pair<int,int>> a;

int find() {
	sort(a.begin(),a.end());
	multiset<int> x1,y1,x2,y2;
	x1.insert(a[0].first);
	y1.insert(a[0].second);
	for(int i=1;i<a.size();i++) {
		x2.insert(a[i].first);
		y2.insert(a[i].second);
	}
	auto area = [&]() {
		int a=*x1.begin(), b=*x1.rbegin(), c=*y1.begin(), d=*y1.rbegin();
		pair<int,int> p; p.first = (b-a)*(d-c);
		a=*x2.begin(), b=*x2.rbegin(), c=*y2.begin(), d=*y2.rbegin();
		p.second = (b-a)*(d-c);
		return p.first+p.second;
	};
	int ret=area();
	for(int i=1;i<a.size()-1;i++) {
		x2.erase(x2.find(a[i].first));
		y2.erase(y2.find(a[i].second));
		x1.insert(a[i].first);
		y1.insert(a[i].second);
		ret=min(ret,area());
	}
	return ret;
}

signed main() {
	#ifndef LJ // g++ -DLJ
	freopen("split.in", "r", stdin); freopen("split.out", "w", stdout);
	#endif

	cin>>n;
	a.resize(n);
	int x1=INT_MAX,y1=INT_MAX,x2=0,y2=0;
	for(int i=0;i<n;i++) {
		cin>>a[i].first>>a[i].second;
		x1=min(x1,a[i].first);
		y1=min(y1,a[i].second);
		x2=max(x2,a[i].first);
		y2=max(y2,a[i].second);
	}
	int ans=find();
	for(int i=0;i<n;i++) swap(a[i].first,a[i].second);
	int x = find();
	ans=min(x,ans);
	cout << (x2-x1)*(y2-y1)-ans << endl;
}
