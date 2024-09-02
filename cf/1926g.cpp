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

const int MN = 1e5+1;
int n;
vi t[MN];
int c[MN];

int dfs(int v) {
	int P=0,S=0,ret=0;
	for(int u : t[v]) {
		ret += dfs(u);
		P+=c[u]==1;
		S+=c[u]==0;
	}
	if(c[v]==-1) {
		if(P>S)
			c[v]=1;
		else if(S>P)
			c[v]=0;
		return ret+min(P,S);
	}
	else if(c[v]==0) return ret+P;
	else return ret+S;
}

signed main() {
	/* ios_base::sync_with_stdio(false); cin.tie(NULL); */
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	int tst;cin>>tst;
	while(tst--) {
		cin>>n;
		for(int i=1;i<=n;i++) t[i].clear();
		for(int i=2;i<=n;i++) {
			int x;cin>>x;
			t[x].push_back(i);
		}
		for(int i=1;i<=n;i++) {
			char ch;cin>>ch;
			if(ch=='C') c[i]=-1;
			else c[i]=(ch=='P');
		}
		cout << dfs(1) << endl;
	}
}
