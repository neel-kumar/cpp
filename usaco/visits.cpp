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

	int n;
	cin >> n;
	int a[n+1], v[n+1];
	vi rev[n+1];
	map<int,int> mp; // dest to cost
	int ans=0;
	for (int i = 1; i <= n; i++) {
		cin>>a[i]>>v[i];
		rev[a[i]].push_back(i);
		ans += v[i];
	}

	bool vis[n+1]={0};
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		int mi=INT_MAX,t=i,h=i;
		do {
			t=a[t];
			h=a[a[h]];
		} while(t!=h);
		do {
			mi=min(mi,v[t]);
			t=a[t];
		} while(t!=h);
		ans-=mi;
		queue<int> q;
		q.push(t);
		while(!q.empty()) {
			int x=q.front();
			q.pop();
			vis[x]=1;
			for(int j:rev[x]) {
				if(!vis[j]) q.push(j);
			}
		}
	}
	cout<<ans<<endl;
}
