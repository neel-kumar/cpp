#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MX = 2e5+1;
int n, a[MX], p[MX], m;

signed main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		p[a[i]]=i;
	}

	int ans = 0, c = INT_MAX;
	for(int i=1; i<=n; i++) {
		if(p[i] < c)
			ans++;
		c = p[i];
	}

	while(m--) {
		int x, y; cin>>x>>y;
		if(p[a[x]-1] < x && p[a[x]-1] >= y) ans++;
		if(p[a[x]-1] > x && p[a[x]-1] <= y) ans--;
		if(p[a[x]+1] > x && p[a[x]+1] <= y) ans++;
		if(p[a[x]+1] < x && p[a[x]+1] >= y) ans--;

		if(p[a[y]-1] < y && p[a[y]-1] > x) ans++;
		if(p[a[y]-1] > y && p[a[y]-1] < x) ans--;
		if(p[a[y]+1] > y && p[a[y]+1] < x) ans++;
		if(p[a[y]+1] < y && p[a[y]+1] > x) ans--;

		swap(a[x], a[y]);
		p[a[x]] = x;
		p[a[y]] = y;

		cout << ans << endl;
	}
}
