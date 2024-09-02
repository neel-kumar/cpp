#include <bits/stdc++.h>
/* #define int long long */
using namespace std;

int n, q, a[(int)1e5], ps[(int)1e5+1];

signed main() {
	cin >> n >> q;
	int l,r,v;
	vector<pair<int,int>> zip;
	for(int i=0;i<n;i++) {
		cin>>l>>r>>v;
		zip.push_back({l,v});
		zip.push_back({r,-v});
	}
	sort(zip.begin(),zip.end());
	vector<pair<int,int>> nzip;
	int c=0,prev=zip[0].first;
	for(auto i : zip) {
		if(i.first == prev) c+=i.second;
		else {
			nzip.push_back({prev,c});
			c=i.second; prev=i.first;
		}
	}
	cout << endl;
	zip=nzip;

	int i=0;
	c=0;
	for(auto z : zip) {
		c+=z.second;
		a[i++]=c;
	}
	ps[0]=0;
	for(int i=0;i<zip.size();i++) ps[i+1]=ps[i]+a[i];
	for(int i = 0; i < 10; i++) cout << ps[i] << ' ';
	cout << endl;

	while(q--) {
		cin>>l>>r;
		pair<int,int> p={l,INT_MIN};
		auto lb=lower_bound(zip.begin(),zip.end(),p);
		p={r,INT_MIN};
		auto rb=lower_bound(zip.begin(),zip.end(),p);
		cout << ps[rb-zip.begin()]-ps[lb-zip.begin()]<< endl;
	}
}
