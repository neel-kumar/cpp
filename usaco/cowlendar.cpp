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
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	int n;cin >> n;
	int ml=INT_MAX;
	set<int> as;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int x;cin>>x;
		ml=min(ml,(int)(x/4));
		if(!as.count(x)) a.push_back(x);
		as.insert(x);
	}
	if(as.size()<4) {
		cout << ml*(ml+1)/2;
		return 0;
	}
	set<int> pos;
	for(int i=0;i<4;i++) {
		for(int j=i+1;j<4;j++) {
			int x=a[i]-a[j];
			x=max(x,-x);
			for(int i=1;i<=sqrt(x);i++) {
				if(x%i==0) {
					pos.insert(i);
					pos.insert(x/i);
				}
			}
		}
	}

	int ans=0;
	for(int i : pos) {
		if(i > ml) break;
		set<int> c;
		for(int j : a) {
			c.insert(j%i);
			if(c.size() > 3)  break;
		}
		if(c.size() <= 3) ans += i;
	}
	cout << ans << endl;
}
