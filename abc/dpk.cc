#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n,k; cin>>n>>k;
	int a[n]; for(int i=0;i<n;i++) cin>>a[i];
	bool dp[k+1] = {0};
	for(int i=0; i<=k; i++) {
		for(int j=0; j<n; j++) if(a[j] <= i && dp[i-a[j]] == 0) {
			dp[i] = 1;
			break;
		}
	}
	cout << (dp[k]?"First\n":"Second\n");
}
