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

char g[7][7];
set<pi> vio;

bool check(int x,int y) {
	int a[4][2]={{-1,-1},{1,-1},{-1,1},{1,1}};
	if(g[x][y]=='W') return false;
	int c=0;
	for(int k=0;k<4;k++) {
		int i=x+a[k][0],j=y+a[k][1];
		c+=(min(i,j)>=0 && max(i,j)<7 && g[i][j]=='B');
	}
	return (c==4);
}

bool dorem(int x,int y,int c) {
	int a[4][2]={{-1,-1},{1,-1},{-1,1},{1,1}};
	for(int k=0;k<4;k++) {
		int i=x+a[k][0],j=y+a[k][1];
		c -= vio.count({i,j});
	}
	return (c==0);
}

void rem(int x,int y) {
	int a[4][2]={{-1,-1},{1,-1},{-1,1},{1,1}};
	for(int k=0;k<4;k++) {
		int i=x+a[k][0],j=y+a[k][1];
		if(vio.count({i,j})) vio.erase(vio.find({i,j}));
	}
	if(vio.count({x,y})) vio.erase(vio.find({x,y}));
}

signed main() {
	/* ios_base::sync_with_stdio(false); cin.tie(NULL); */
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	int T;cin>>T;
	while(T--) {
		vio.clear();
		for(int i=0;i<7;i++)
			for(int j=0;j<7;j++)
				cin>>g[i][j];
		for(int i=0;i<7;i++) {
			for(int j=0;j<7;j++) {
				if(check(i,j))
					vio.insert({i,j});
			}
		}

		int ans=0, c=5;
		while(c>0 && vio.size()) {
			for(int i=0;i<7;i++) {
				for(int j=0;j<7;j++) {
					if(vio.size()==0) break;
					if(dorem(i,j,c)) {
						cout << i << ' ' << j << endl;
						rem(i,j);
						ans++;
					}
				}
			}
			c--;
		}
		cout << ans << endl;
	 }
}
