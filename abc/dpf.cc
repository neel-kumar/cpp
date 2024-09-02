#include <bits/stdc++.h>
/* #define int long long */
using namespace std;

string s,t;
int m[3000][3000];
bool done[3000][3000];
int back[3000][3000][2];

int dp(int i, int j) {
	if(done[i][j]) return m[i][j];
	if(i < 0 || j < 0) return 0;

	int x=dp(i-1,j), y=dp(i,j-1), z=dp(i-1,j-1)+(s[i]==t[j]);
	int fin = x;
	back[i][j][0]=i-1; back[i][j][1]=j;
	if(fin < y) {
		fin=y;
		back[i][j][0]=i; back[i][j][1]=j-1;
	}
	if(fin < z) {
		fin=z;
		back[i][j][0]=i-1; back[i][j][1]=j-1;
	}
	done[i][j]=1;
	return m[i][j]=fin;
}

signed main() {
	cin >> s >> t;
	dp(s.size()-1, t.size()-1);

	int i=s.size()-1, j=t.size()-1, ti, tj;
	string ans = "";
	while(i >= 0 && j >= 0) {
		ti = back[i][j][0], tj = back[i][j][1];
		if(i-1 == ti && j-1 == tj && s[i]==t[j]) ans += s[i];
		i=ti, j=tj;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}
