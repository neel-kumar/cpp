#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5;
int n,m,r;
int prod[N], rent[N];
array<int,2> pq[N];

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef LJ // g++ -DLJ
	freopen("rental.in", "r", stdin); freopen("rental.out", "w", stdout);
	#endif
	cin>>n>>m>>r;
	for(int i=0;i<n;i++) cin>>prod[i];
	for(int i=0;i<m;i++) cin>>pq[i][1]>>pq[i][0];
	for(int i=0;i<r;i++) cin>>rent[i];

	sort(prod,prod+n); reverse(prod,prod+n);
	sort(pq,pq+m); reverse(pq,pq+m);
	sort(rent,rent+r);
	int ri=n-1, pi=0, ans=0;
	for(int i=0;i<n;i++) {
		int ans1=0, ans2=0;
		if(pi<m) {
			while(pi<m && prod[i]>=pq[pi][1]) {
				ans1+=pq[pi][1]*pq[pi][0];
				prod[i]-=pq[pi][1];
				pi++;
			}
			if(pi<m) {
				pq[pi][1]-=prod[i];
				ans1+=prod[i]*pq[pi][0];
			}
		}
		if(ri>=0) {
			if(ri<r) ans2=max(ans2,rent[r-ri-1]);
			ri--;
		}
		ans+=max(ans1,ans2);
	}
	cout << ans << endl;
}
