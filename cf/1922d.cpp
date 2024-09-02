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
 */
using ld = long double;
#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		int a[n+2],d[n+2];
		set<int> check;
		set<int> alive;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++) {
			cin>>d[i];
			alive.insert(i);
			check.insert(i);
		}
		alive.insert(0);
		alive.insert(n+1);
		a[0]=0,a[n+1]=0,d[0]=INT_MAX,d[n+1]=INT_MAX;

		for(int i=0;i<n;i++) {
			set<int> die;
			set<int> chk;
			for(int m : check) {
				if(!alive.count(m)) continue;
				auto it = alive.find(m);
				int p=*prev(it),n=*next(it);
				if(d[m] < a[p]+a[n]) {
					die.insert(m);
					chk.insert(p);
					chk.insert(n);
				}
			}
			cout << die.size() << ' ';
			for(int x:die) alive.erase(x);
			check=chk;
		}
		cout << '\n';
	}
}
