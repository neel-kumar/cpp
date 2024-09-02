#include <bits/stdc++.h>
using namespace std;

int n, m, a,b;
vector<int> g[1010];
int da[1010], db[1010];
bool vis[1010];

int main() {
	cin >> n >> m >> a >> b;
	a--; b--;
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	queue<int> q;
	for(int i = 0; i < n; i++) da[i] = 5000;
	for(int i = 0; i < n; i++) db[i] = 5000;
	da[a] = 0; db[b] = 0;
	q.push(a);
	while(!q.empty()) {
		int x = q.front();
		vis[x] = true;
		q.pop();
		for(int i : g[x]) {
			if(da[i] == 5000) {
				da[i] = da[x]+1;
				q.push(i);
			}
		}
	}
	q.push(b);
	while(!q.empty()) {
		int x = q.front();
		vis[x] = true;
		q.pop();
		for(int i : g[x]) {
			if(db[i] == 5000) {
				db[i] = db[x]+1;
				q.push(i);
			}
		}
	}

	// final bfs
	for(int i = 0; i < n; i++) vis[i] = false;
	queue<int> qu;
	qu.push(a);
	int ans = 0;
	int a2b = da[b];
	for(int x = 0; x < n; x++) {
		bool con[n]; for(int i = 0; i < n; i++) con[i] = false;
		con[x] = true;
		for(int i : g[x]) con[i] = true;
		for(int i = 0; i < n; i++) {
			if(!con[i] && a2b <= min(da[x]+db[i]+1, db[x]+da[i]+1)) ans++;
			//if(!con[i]) cout << "NEWPATH " << x+1 << " " << i+1 << " " << da[x]+db[i]+1 << " " << db[x]+da[i]+1 << endl;
		}
	}

	cout << ans/2 << endl;

	return 0;
}
