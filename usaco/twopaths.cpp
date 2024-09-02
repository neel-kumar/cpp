#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m, k; cin >> n >> m >> k;
	k = max(k, 1);
	int a[m][m], b[m][m], g[n][m];
	for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> g[i][j];
	memset(a, -2000000, sizeof(a));
	memset(b, 0, sizeof(b));

	for(int r=n-1; r>0; r--) {
		// forget about last row to move forward and save mem
		for(int i=0; i<m; i++) for(int j=0; j<m; j++) a[i][j]=b[i][j];
		memset(b, -2000000, sizeof(b));
		// dp
		for(int i=0; i<m; i++) {
			int rs=g[r][i];
			for(int j=(r?i+1:i+k+1); j<m; j++) {
				rs+=g[r][j];
				b[i][j] = max(b[i][j], a[i][j]+rs);
				if(j-1 != i) b[i][j-1] = max(b[i][j-1], a[i][j]+rs);
				if(i != 0) {
					b[i-1][j] = max(b[i-1][j], a[i][j]+rs);
					b[i-1][j-1] = max(b[i-1][j-1], a[i][j]+rs);
				}
			}
		}
	}

	// max of final row
	int ans = INT_MIN;
	for(int i=0; i<m; i++) {
		int rs=g[0][i];
		for(int j=i+1; j<m; j++) {
			rs+=g[0][j];
			ans = max(ans, rs+b[i][j]);
		}
	}
	cout << ans << endl;
}

signed main() {
	int t; cin >> t;
	while(t--) solve();
}
