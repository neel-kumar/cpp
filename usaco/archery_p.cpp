#include <bits/stdc++.h>
using namespace std;

int n;
set<int> p[1000001];
int a[1000001];

signed main() {
	cin >> n;
	for(int i=0;i<n;i++) {
		int x; cin >> x;
		a[i]=x;
		p[x].insert(i);
	}

	// trav
	int ans=0;
	bool v[n];
	memset(v,0,sizeof(v));
	for(int i=0;i<n;i++) {
		if(v[i]) continue;
		ans++;
		int j=i;
		v[i]=true;
		while(!p[a[j]-1].empty()) {
			auto it=p[a[j]-1].upper_bound(j);
			if(it == p[a[j]-1].end()) break;
			j=(*it);
			p[a[j]].erase(it);
			v[j]=true;
		}
	}
	cout << ans << endl;
}
