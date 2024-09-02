#include <iostream>
#include <array>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

int n,s;
char g[800][800];
int v[800][800];
array<int,4> fx = {-1,1,0,0};
array<int,4> fy = {0,0,-1,1};
pair<int,int> h;
pair<int,int> f;

bool check(int st) {
	// takes the start time and then trav
	int d[800][800];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			d[i][j]=-1;
	memset(d,0,sizeof(d));
	queue<pair<int,int>> q;
	q.push(h);
	d[h.first][h.second]=0;
	d
	while(!q.empty()) {
		if(q.front() == f) return true;
		int x=q.front().first,y=q.front().second; q.pop();
		cerr << x << ' ' << y << " | " << d[x][y] << endl;

		for(int k=0;k<4;k++) {
			int i=fx[k]+x,j=fy[k]+y;
			if(i < 0 || i >= n || j < 0 || j >= n) continue;
			if(d[i][j] > 0 || (g[i][j] != 'G' && g[i][j] != 'D')) continue;
			d[i][j]=d[x][y]+1;
			if( ((d[i][j])/s)+st >= v[i][j]-1 ) continue;
			else {
				q.push({i,j});
			}
		}
	}
	return false;
}

signed main() {
	cin >> n >> s;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin >> g[i][j];
			if(g[i][j]=='M')
				h={i,j};
			else if(g[i][j]=='D')
				f={i,j};
		}
	}

	// 01bfs for guardians
	queue<pair<int,int>> q;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(g[i][j]=='H') {
				v[i][j]=1;
				q.push({i,j});
			}
		}
	}

	int t=1;
	while(!q.empty()) {
		int x=q.front().first,y=q.front().second; q.pop();
		if(v[x][y] > t) t=v[x][y];
		for(int k=0;k<4;k++) {
			int i=fx[k]+x,j=fy[k]+y;
			if(i < 0 || i >= n || j < 0 || j >= n) continue;
			if(v[i][j] || g[i][j] == 'T') continue;
			else {
				v[i][j]=t+1;
				q.push({i,j});
			}
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cerr << v[i][j] << ' ';
			if(v[i][j] == 0) v[i][j] = INT_MAX;
		}
		cerr << endl;
	}
	cerr << endl;

	if(v[h.first][h.second] == INT_MAX && check(0)) {
		cout << '0' << endl;
		return 0;
	}
	// final bs with check func that does a traversal
	int l=0, r=v[h.first][h.second];
	if(check(0) == 0) {
		cout << "-1\n";
		return 0;
	}
	while(l<r) {
		int mid = (l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout << l << endl;
}
