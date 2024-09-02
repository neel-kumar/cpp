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

	int t;cin>>t;
	while(t--) {
		int e,n,b;cin>>e>>n>>b;
		bool a[n]={0};
		vector<array<int,2>> g(n);
		for(int i=0;i<n;i++) {
			int mine=INT_MAX,mino=INT_MAX,maxe=0,maxo=0;
			for(int j=0;j<b;j++) {
				int x; cin>>x;
				if(x%2==0) {
					maxe=max(maxe,x);
					mine=min(mine,x);
				} else {
					maxo=max(maxo,x);
					mino=min(mino,x);
				}
			}
			if(maxe==0) g[i][1]=-mino;
			else g[i][1]=maxe;
			if(maxo==0) g[i][0]=-mine;
			else g[i][0]=maxo;

			if(g[i][0]<=g[i][1]) a[i]=0;
			else a[i]=1;
		}

		int x=e;
		for(int i=0;i<n;i++)
			x-=g[i][a[i]];
		if(x<=0) {
			cout << "-1\n";
			continue;
		}

		int curr=e,currb=e;
		for(int i=0;i<n;i++) {
			if(a[i]==1) {
				int c=curr-g[i][0];
				int cb=currb+g[i][0];
				for(int j=i+1;j<n;j++) {
					if(c<=0) break;
					if(cb<=0) break;
					c-=g[j][a[j]];
					cb+=g[j][a[j]];
				}
				if(c>0)
					a[i]=0;
			}
			curr -= g[i][a[i]];
			currb += g[i][a[i]];
		}

		for(int i=0;i<n;i++) {
			if(a[i]==0) cout << "Even";
			else cout << "Odd";
			if(i!=n-1) cout<<" ";
		}
		cout<<endl;
	}
}
