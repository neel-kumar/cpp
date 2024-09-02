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
 */
using ld = long double;
using ll = long long;
#define f first
#define s second

int check(vector<vector<bool>> &g, int n, int m, int k) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++)
			cout << g[i][j] << ' ';
		cout << endl;
	}
	// make prefix sums
	int pn[n][m+1]={0}, pm[m][n+1]={0};
	for(int i=0;i<n;i++) {
		for(int j=1;j<=m;j++)
			pn[i][j]=pn[i][j-1]+g[i][j-1];
	}
	for(int i=0;i<m;i++) {
		for(int j=1;j<=n;j++)
			pm[i][j]=pn[i][j-1]+g[j-1][i];
	}

	int pd[n+m][min(n,m)]={0};
	for(int i=0;i<n+m-1;i++) {
		for(int j=max(0,i-m+1);j<=min(n-1,i);j++) {
			pd[i][j+1]=pd[i][j]+g[j][i-j];
			cout << pd[i][j+1] << ' ';
		}
		cout << endl;
	}

	/*
	 * ....
	 * ...
	 * ..
	 * .
	 */

	int mx=0;
	queue<array<int,3>> q;
	int x=0;
	for(int i=0;i<k;i++) {
		for(int j=0;j<k-i;i++) {
			if(i < n && j < m)
				x+=g[i][j];
		}
	}
	q.push({0,0,x});
	set<pi> v;
	while(!q.empty()) {
		array<int,3> c=q.front(); q.pop();
		if(v.count({c[0],c[1]})) continue;
		v.insert({c[0],c[1]});
		mx=max(mx,c[2]);
		if(c[0]<n)
			q.push({c[0]+1,c[1],c[2]
					-(pn[c[0]][min(c[1]+k,m)]-pn[c[0]][c[1]])});
		if(c[1]<m)
			q.push({c[0],c[1]+1,c[2]
					-(pm[c[1]][min(c[0]+k,n)]-pm[c[1]][c[0]])});
	}
	return mx;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	int t; cin >> t;
	while(t--) {
		int n,m,k;
		vector<vector<bool>> a;
		cin>>n>>m>>k;
		a.resize(n,vector<bool>(m));
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				char c; cin >> c;
				a[i][j]=(c=='#');
			}
		}

		int mx=0;
		for(int i=0;i<4;i++) {
			vector<vector<bool>> ta;
			ta.resize(a[0].size(),vector<bool>(a.size()));
			for(int i=0;i<a.size();i++)
				for(int j=0;j<a[0].size();j++)
					ta[j][a.size()-i-1]=a[i][j];
			mx=max(check(ta,ta.size(),ta[0].size(),k),mx);
			a=ta;
		}
	}
}
