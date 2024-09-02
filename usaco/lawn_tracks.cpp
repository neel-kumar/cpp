#include <bits/stdc++.h>
using namespace std;

int n,m;
char G[4000][4000];
bool v[4000][4000];
deque<pair<int,int>> q;

int bfs(char t) {
    cerr << "NEWBFS: " << t << ' ' << q.size() << endl;
    if(q.empty()) return 0;
    int tx[4]={1,0,-1,0}, ty[4]={0,1,0,-1};
    while(!q.empty()) {
	if(G[q.front().first][q.front().second] != t) break;
	pair<int,int> p = q.front(); q.pop_front();

	for(int i = 0; i < 4; i++) {
	    int nx = p.first+tx[i], ny = p.second+ty[i];
	    if(nx < 0 || nx >= n || ny < 0 || ny >= m || G[nx][ny]=='.' || v[nx][ny]) continue;

	    cerr << nx << ' ' << ny << ' ' << G[nx][ny] << endl;
	    if(G[nx][ny] == t) q.push_front({nx,ny});
	    else {
		q.push_back({nx,ny});
	    }
	    v[nx][ny] = 1;
	}
    }
    return 1+bfs(t=='F'?'R':'F');
}

signed main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) {
	    cin >> G[i][j];
	}
    }

    q.push_back({0,0});
    cout << bfs(G[0][0]) << endl;
}
