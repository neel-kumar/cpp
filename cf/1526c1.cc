#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n; cin>>n;
	int a[n];
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		v.push_back({a[i],i});
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());

	bool take[n]={0};
	for(pair<int,int> i : v) {
		take[i.second]=1;
		int c=0;
		bool works=true;
		for(int j=0;j<n && works;j++) {
			if(take[j]) c+=a[j];
			if(c<0) works=false;
		}
		take[i.second]=works;
	}
	int ans=0;
	for(int i=0;i<n;i++) ans+=take[i];
	cout << ans << endl;
}
