#include <bits/stdc++.h>
using namespace std;

int n,k;
int mod;

bool cmp(int a,int b) {
	return (a%mod) > (b%mod);
}

signed main() {
	freopen("berries.in", "r", stdin);
	freopen("berries.out", "w", stdout);

	cin>>n>>k;
	int x;
	int mb=0;
	int a[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
		mb=max(mb,a[i]);
	}

	int ans=0;
	for(int b=1;b<=mb;b++) {
		int bc=0;
		for(int i=0;i<n;i++) bc+=a[i]/b;
		if(bc < k/2) break;
		if(bc>=k) {
			ans=max(ans,b*(k/2));
			continue;
		}
		mod=b;
		sort(a,a+n,cmp);
		int cu=(b*(bc-k/2));
		for(int i=0;i<n && i+bc<k;i++) cu+=a[i]%b;
		ans=max(ans,cu);
	}

	cout << ans << endl;
}
