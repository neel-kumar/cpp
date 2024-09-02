#include <bits/stdc++.h>
/* #define int long long */
using namespace std;

signed main() {
	/* ios_base::sync_with_stdio(false); cin.tie(NULL); */
	#ifndef LJ // g++ -DLOCAL_JUDGE
	freopen("art.in", "r", stdin); freopen("art.out", "w", stdout);
	#endif

	int n; cin>>n;
	int g[n][n];
	map<int,array<int,4>> c; // x1,y1,x2,y2
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			int x; cin >> x; g[i][j]=x;
			if(x==0) continue;
			if(c.count(x)==0) {
				c[x]={1000,1000,-1,-1};
			}
			c[x][0]=min(c[x][0],i);
			c[x][1]=min(c[x][1],j);
			c[x][2]=max(c[x][2],i);
			c[x][3]=max(c[x][3],j);
		}
	}

	if(c.size() > 1) {
		int dif[n][n+1]; memset(dif,0,sizeof(dif));
		for(const auto& [k,v] : c) {
			if(k == 0) continue;
			for(int i=v[0];i<=v[2];i++) {
				dif[i][v[1]]++;
				dif[i][v[3]+1]--;
			}
		}

		set<int> rem;
		for(int i=0;i<n;i++) {
			int cu=0;
			for(int j=0;j<n;j++) {
				cu+=dif[i][j];
				if(cu > 1) rem.insert(g[i][j]);
			}
		}
		cout << n*n-rem.size() << endl;
	} else {
		cout << n*n-1 << endl;
	}
}
