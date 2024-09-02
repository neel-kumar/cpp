/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") */
#include <bits/stdc++.h>
using namespace std;
#define int long long
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

signed main() {
	/* ios_base::sync_with_stdio(false); cin.tie(NULL); */
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	int n;cin>>n;
	int a[n+1]; for(int i=0;i<n;i++) cin>>a[i];
	a[n]=0;
	string ans="";
	int i=0;
	while(!(i==0 && a[i]==0)) {
		while(a[i]>0 && i<=n) {
			a[i]--;
			i++;
			ans+='R';
		}
		while(i>0 && (a[i-1]>1 || a[i]==0)) {
			i--;
			a[i]--;
			ans+='L';
		}
	}
	cout<<ans<<endl;
}

