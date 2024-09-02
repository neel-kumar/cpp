#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n,x,y,b; cin>>n>>x>>y>>b;
	int a[n]; for(int i=0;i<n;i++) cin>>a[i];

	int ans=0;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			int mn = a[i], mx = a[i];
			if(a[i] == b) continue;
			bool works = 1;
			for(int k=i+1;k<=j;k++) {
				mn = min(mn,a[k]);
				mx = max(mx,a[k]);
				if(a[k] == b) {
					works = 0;
					break;
				}
			}
			ans += (works && mn==y && mx==x);
		}
	}

	cout << ans << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
