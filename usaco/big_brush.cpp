#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
using ld = long double;
#define f first
#define s second
template<typename... Args>
void print(Args... args) {
    ((cerr << args << " "), ...);
    cerr << endl;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n,m; cin >> n >> m;
	int g[n][m];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			cin >> g[i][j];
	}

	queue<pi> q;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(i<n-1 && j<n-1 && g[i][j]==g[i+1][j] && g[i][j]==g[i][j+1] && g[i][j]==g[i+1][j+1])
				q.push({i,j});
		}
	}

	vector<array<int, 3>> ans;
	int cy[11] = {-1,-1,-1,-1,0,0,0,1,1,1,1};
	int cx[11] = {-1,0,1,2,-1,1,2,-1,0,1,2};
	set<pi> vis;
	set<pi> ch;

	while(!q.empty() && ch.size() < n*m) {
		pi c = q.front(); q.pop();
		if(vis.count(c)) continue;
		vis.insert(c);
		int x = -1;
		for(int i = c.f; i < c.f+2; i++) {
			for(int j = c.s; j < c.s+2; j++) {
				if(g[i][j] != -1) x = g[i][j];
				g[i][j] = -1;
				ch.insert({i,j});
			}
		}
		if(x == -1) continue;
		ans.push_back({c.f+1, c.s+1, x});

		for(int x = 0; x < 11; x++) {
			set<int> s;
			bool works = true;
			for(int i = cx[x]; i < cx[x]+2; i++) {
				for(int j = cy[x]; j < cy[x]+2; j++) {
					if(!(c.f+i >= 0 && c.f+i < n && c.s+j >= 0 && c.s+j < m)) works=false;
					else s.insert(g[c.f+i][c.s+j]);
				}
			}
			if(works && (s.size()==1 || (s.count(-1) && s.size()==2)) && !vis.count({c.f+cx[x], c.s+cy[x]}))
				q.push({c.f+cx[x], c.s+cy[x]});
		}
	}

	if(ch.size() == n*m) {
		cout << ans.size() << endl;
		for(int i = ans.size()-1; i >= 0; i--) {
			for(auto j : ans[i]) cout << j << " ";
			cout << endl;
		}
	} else {
		cout << -1 << endl;
	}
}
