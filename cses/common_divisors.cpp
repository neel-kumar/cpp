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
 *
 * priority_queue <int, vector<int>, greater<int> > pq; minheap
 */
using ld = long double;
using ll = long long;
#define f first
#define s second

const int MV=1e6;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	/* int n;cin>>n; */
	/* int d[(int)1e6 + 1]={0}; */
	/* for(int i=0;i<n;i++) { */
	/* 	int a;cin>>a; */
	/* 	for(int f=1;f*f<=a;f++) { */
	/* 		if(a%f) continue; */
	/* 		d[f]++; */
	/* 		if(f*f!=a) */
	/* 			d[a/f]++; */
	/* 	} */
	/* } */

	/* for(int i=(int)1e6; i>=1; i--) { */
	/* 	if(d[i]>1) { */
	/* 		cout<<i<<endl; */
	/* 		return 0; */
	/* 	} */
	/* } */

	int n;cin>>n;
	int a[MV+1]={0};
	for(int i=0;i<n;i++) {
		int x;cin>>x;a[x]++;
	}
	for(int ans=MV;ans>0;ans--) {
		int c=0;
		for(int chk=ans;chk<=MV;chk+=ans) c+=a[chk];
		if(c>1) {
			cout<<ans<<endl;
			return 0;
		}
	}
}
