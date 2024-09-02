/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") */
#include <bits/stdc++.h>
using namespace std;
/* #define int long long */
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef bitset<1000000001> bs;
/*
 * bs[i]        =>  set.count(i)
 * bs.set(i)    =>  set.insert(i)
 * bs.reset(i)  =>  set.erase(i)
 * bs.count()   =>  set.size()
 */
using ld = long double;
using ll = long long;
#define f first
#define s second

signed main() {
	/* ios_base::sync_with_stdio(false); cin.tie(NULL); */
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	int t; cin >> t;
	while(t--) {
		int n; cin>>n;
		int a[n],p[n];
		for(int i=0;i<n;i++) {
			cin>>a[i];
			p[a[i]]=i;
		}

		int l=p[0],r=p[0];
		ll ans=1;
		for(int x=1;x<n;x++) {
			if(x&1) {
				int i=x/2;
				l=min(p[i],l);
				r=max(p[i],r);
			}
			int st=max(0,r-x+1),nd=min(l+x-1,n-1)-x+1;
			if(st > nd) continue;
			ans += nd-st+1;
		}
		cout << ans << endl;
	}
}
