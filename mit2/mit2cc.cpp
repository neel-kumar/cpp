/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") */
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
using ld = long double;
#define f first
#define s second

const int N = 2e5;
int n,m;
vector<array<int,3>> g[N+1];

bool check(int coins) {
	bool v[n+1];
	memset(v,0,sizeof(v));
    priority_queue<pi,vector<pi>,
		greater<pi> >pq; // $left, node
	pq.push({coins,1});
	while(!pq.empty()) {
		pi t=pq.top(); pq.pop();
		if(t.s==n) return true;
		if(v[t.s]) continue;
		v[t.s]=1;
		for(array<int,3> i : g[t.s]) {
			if(t.f < i[1]) continue;
			else if(i[2] > i[1]) return true;
			else pq.push({t.f-i[1]+i[2], i[0]});
		}
	}

	return false;
}

signed main() {
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		int a,b,c,d; cin>>a>>b>>c>>d;
		g[a].push_back({b,c,d});
		g[b].push_back({a,c,d});
	}

	// bs
	int l=0,r=INT_MAX;
	while(l<r) {
		int mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	cout<<l<<endl;
}
