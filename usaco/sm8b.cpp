#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> t[501];
int td[501][501];
int ans[501][501];

void bfs(int r) {
	queue<pair<int,int>> q;
	q.push({r,-1});
	int d[n+1];
	memset(d,-1,sizeof(d));
	d[r] = 0;
	while(!q.empty()) {
		pair<int,int> p = q.front(); q.pop();
		for(int i : t[p.first]) {
			if(i==p.second || d[i] != -1) continue;
			d[i] = d[p.first]+1;
			q.push({i,p.first});
		}
	}
	for(int i = 1; i <= n; i++) td[r][i] += d[i];
}


signed main() {
	cin >> n >> k;
	for(int j=0; j<k; j++) {
		for(int i=1; i < n; i++) {
			int a, b; cin >> a >> b;
			t[a].push_back(b);
			t[b].push_back(a);
		}
		for(int i = 1; i <= n; i++) {
			bfs(i);
		}
		for(int i = 1; i <= n; i++) {
			t[i].clear();
		}
	}


	for(int i = 1; i <= n; i++) {
		ans[i][i] = 1;
		for(int j = i+1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				ans[i][j] += (td[i][k]+td[j][k])==td[i][j];
				ans[j][i] += (td[i][k]+td[j][k])==td[i][j];
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}
