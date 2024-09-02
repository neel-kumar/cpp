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

int n,m,k;
map<int,int> p[21][21];
int g[21][21];
int ans;
int hf;

void bfs(bool b) {
	int x=(b?n-1:0), y=(b?m-1:0);
	queue<array<int,3>> q;
	q.push({x,y,0});
	while(!q.empty()) {
		array<int,3> c=q.front(); q.pop();
		if(c[0]>=n || c[1]>=m || c[0]<0 || c[1]<0) continue;
		if((c[0]+c[1])==hf) {
			if(!b) {
				p[c[0]][c[1]][c[2]^g[c[0]][c[1]]]++;
			} else {
				ans += p[c[0]][c[1]][c[2]^k];
			}
		} else {
			q.push({c[0]+(b?-1:1),c[1],c[2]^g[c[0]][c[1]]});
			q.push({c[0],c[1]+(b?-1:1),c[2]^g[c[0]][c[1]]});
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	cin>>n>>m>>k;
	hf=(n+m-2)/2;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>g[i][j];
	bfs(0);
	ans=0;
	bfs(1);
	cout << ans << endl;
}
