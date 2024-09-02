#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n,m; cin >> n >> m;
	int a[n]; for(int i=0; i<n; i++) cin >> a[i];
	sort(a,a+n);

	map<int,int> mp;
	int ans=INT_MAX,r=0,cnt=0;
	for(int l=0; l<n; l++) {
		/* cout<<"TRAV "<<l<<" "<<r<<" "<<cnt<<endl; */
		while(r<n && cnt<m) {
			// all factors
			int x = a[r];
			for(int i=1;i*i<=x;i++) {
				if(x%i==0) {
					if(i<=m) {
						cnt+=(mp[i]==0);
						mp[i]++;
					}
					if(i*i!=x && (x/i)<=m) {
						cnt+=(mp[x/i]==0);
						mp[x/i]++;
					}
				}
			}
			/* cout << a[r] << '=' << r << ' ' << cnt << endl; */
			r++;
		}

		if(cnt==m) ans = min(ans, a[r-1]-a[l]);
		int x = a[l];
		for(int i=1;i*i<=x;i++) {
			if(x%i==0) {
				if(i<=m) {
					mp[i]--;
					cnt-=(mp[i]==0);
				}
				if(i*i!=x && i<=m) {
					mp[x/i]--;
					cnt-=(mp[x/i]==0);
				}
			}
		}
	}
	cout<<(ans==INT_MAX?-1:ans)<<endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
