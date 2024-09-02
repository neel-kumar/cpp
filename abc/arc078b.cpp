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
	/* ios_base::sync_with_stdio(false); cin.tie(NULL); */
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	int n; cin>>n;
	vi g[n+1];
	int v[n+1]; memset(v,0,sizeof(v));

	for(int i=1;i<n;i++) {
		int a,b; cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int s=1,f=1;
	v[1]=1; v[n]=2;
	queue<pi> q;
	q.push({1,1});
	q.push({n,2});
	while(!q.empty()) {
		pi i=q.front(); q.pop();
		v[i.f]=i.s;
		for(int j : g[i.f]) {
			if(!v[j]) {
				v[j]=i.s;
				f+=i.s==1;
				s+=i.s==2;
				q.push({j,i.s});
			}
		}
	}
	/* cout<<f<<' '<<s<<endl; */
	if(s<f) cout<<"Fennec\n";
	else cout<<"Snuke\n";
}
