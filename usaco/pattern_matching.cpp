#include <bits/stdc++.h>
using namespace std;

string p;
vector<vector<char> > g;
int m, n;
map<int, int> ms;

int keyify(int i, int j) {
//	stringstream s;
//	s<<g[i][j]<<g[i][j+1]<<g[i+1][j]<<g[i+1][j+1];
//	return s.str();

	return g[i][j]-'a' + 1e2*(g[i][j+1]-'a') + 1e4*(g[i+1][j]-'a') + 1e6*(g[i+1][j+1]-'a');
}

int keyp() {
	return p[0]-'a' + 1e2*(p[1]-'a') + 1e4*(p[2]-'a') + 1e6*(p[3]-'a');
}

void update(int i, int j, int val) {
	if(i < 0 || j < 0 || j+1 >= m || i+1 >= n) return;
	ms[keyify(i, j)] += val;
}

void pchange(int i, int j, char c) {
	p[ (i*2)+j ] = c;
}

void gchange(int i, int j, char c) {
	update(i-1, j-1, -1);
	update(i-1, j, -1);
	update(i, j-1, -1);
	update(i, j, -1);

	g[i][j] = c;

	update(i-1, j-1, 1);
	update(i-1, j, 1);
	update(i, j-1, 1);
	update(i, j, 1);
}

signed main() {
	int q; cin >> n >> m >> q;
	for(int i = 0; i < n; i++) {
		vector<char> v(m);
		for(int j = 0; j < m; j++) cin >> v[j];
		g.push_back(v);
	}
	p = "";
	for(int i = 0; i < 4; i++) {
		char x; cin >> x;
		p += x;
	}

	for(int i = 0; i < n-1; i++) {
		for(int j = 0; j < m-1; j++) {
			update(i, j, 1);
		}
	}

	cout << ms[keyp()] << endl;
	while(q--) {
		int t,i,j; cin >> t >> i >> j; i--; j--;
		char c; cin >> c;
		if(t == 1) gchange(i, j, c);
		if(t == 2) pchange(i, j, c);

		cout << ms[keyp()] << endl;
	}
}
