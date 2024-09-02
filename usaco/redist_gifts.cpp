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

int n;
vi a[501];
int ans[501];
set<int> vis;

bool dfs(int x, int tar) {
	if(x==tar) return true;
	if(vis.count(x)) return false;
	vis.insert(x);
	for(int y : a[x]) {
		if(dfs(y,tar)) return true;
	}
	return false;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	cin>>n;
	for(int i=1;i<=n;i++) {
		bool found=false;
		ans[i]=i;
		for(int j=0;j<n;j++) {
			int x;cin>>x;
			found |= x==i;
			if(!found) a[i].push_back(x);
		}
	}

	for(int i=1;i<=n;i++) {
		vis.clear();
		bool works=false;
		for(int j : a[i]) {
			if(dfs(j,i)) {
				cout << j << endl;
				works=true;
				break;
			}
		}
		if(!works) cout << i << endl;
	}
}
