#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
using ld = long double;
#define f first
#define s second
template<typename... Args>
void print(Args... args) {
    ((cerr << args << " "), ...);
    cerr << endl;
}

const int MOD=1e9+7;
int n,m;

/* int f(int i, vector<pi> &v, vector<vector<char>> &g) { */
/* 	if(i == v.size()) return 1; */
/* 	int ans=0; */
/* 	int nt[4][2][2] = { {{0,1},{1,0}}, {{0,1},{-1,0}}, {{0,-1},{1,0}}, */
/* 		{{0,-1},{-1,0}} }; */
/* 	for(int j=0;j<4;j++) { */
/* 		int x = v[i].f + nt[j][0][0], y = v[i].s + nt[j][0][1]; */
/* 		int x1 = v[i].f + nt[j][1][0], y1 = v[i].s + nt[j][1][1]; */
/* 		if (min(x,x1) < 0 || max(x,x1) >= n */
/* 			|| min(y,y1) < 0 || max(y,y1) >= m */
/* 			|| g[x][y] != '.' || g[x1][y1] != '.') continue; */
/* 		g[x][y] = g[x1][y1] = 'x'; */
/* 		ans += f(i+1, v, g); */
/* 		g[x][y] = g[x1][y1] = '.'; */
/* 	} */
/* 	return ans; */
/* } */

int f(int i, vector<pi> &v, vector<vector<char>> &g) {
	if(i == v.size()) return 1;
	int cnt=0;
	int nt[4][2][2] = { {{0,1},{1,0}}, {{0,1},{-1,0}}, {{0,-1},{1,0}},
		{{0,-1},{-1,0}} };
	for(int j=0;j<4;j++) {
		int x = v[i].f + nt[j][0][0], y = v[i].s + nt[j][0][1];
		int x1 = v[i].f + nt[j][1][0], y1 = v[i].s + nt[j][1][1];
		if (min(x,x1) < 0 || max(x,x1) >= n
			|| min(y,y1) < 0 || max(y,y1) >= m
			|| g[x][y] != '.' || g[x1][y1] != '.') continue;
		cnt++;
	}
	return (cnt * f(i+1, v, g))%MOD;
}

void solve() {
	cin>>n>>m;
	vector<vector<char>> g(n, vector<char>(m));
	vector<pi> v;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>g[i][j];
			if(g[i][j] == 'o') v.push_back({i,j});
		}
	}

	cout << f(0, v, g) << endl;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t;cin>>t;
	while(t--) solve();
}
