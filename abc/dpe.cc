#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;

signed main() {
	int n,W; cin>>n>>W;
	int w[n], v[n]; for(int i=0; i<n; i++) cin>>w[i]>>v[i];

	int dp[MAXN];
	for(int i=0; i<MAXN; i++) dp[i]=INT_MAX;
	dp[0]=0;
	for(int i=0; i<n; i++) {
		for(int j=MAXN-1; j>=0; j--) {
			if(dp[j]!=INT_MAX && dp[j]+w[i] <= W) {
				dp[j+v[i]] = min(dp[j+v[i]], dp[j]+w[i]);
			}
		}
	}

	for(int i=MAXN-1; i>=0; i--) if(dp[i]!=INT_MAX) {
		cout << i << endl;
		return 0;
	}
}
