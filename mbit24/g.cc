#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	char g[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>g[i][j];

	int ans=0;
	char mbit[4] = {'M','B','I','T'};
	for(int i2=0;i2<4;i2++) {
		for(int j2=i2+1;j2<4;j2++) {
			/* cout << "CHARS: " << mbit[i2] << ' ' << mbit[j2] << endl; */

			int notij[n][n];
			memset(notij,0,sizeof(notij));
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					for(int k=j+1;k<n;k++) {
						if( g[i][j]!=g[i][k] && g[i][j]!=mbit[i2] && g[i][j]!=mbit[j2]
								&& g[i][k]!=mbit[i2] && g[i][k]!=mbit[j2]) {
							notij[j][k]++;
							/* cout << j << '-' << k << " --> " << g[i][j] << ' ' << g[i][k] << endl; */
						}
					}
				}
			}

			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					for(int k=j+1;k<n;k++) {
						if((g[i][j]==mbit[i2] && g[i][k]==mbit[j2]) || (g[i][j]==mbit[j2] && g[i][k]==mbit[i2])) {
							ans += notij[j][k];
							/* cout << j << '-' << k << " --> " << notij.count({j,k}) << endl; */
						}
					}
				}
			}

		}
	}

	cout << ans/2 << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}
