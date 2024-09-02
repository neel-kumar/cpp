#include <bits/stdc++.h>
using namespace std;

int dp[1000001];
int n, x;
int c[100];


signed main() {
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
		cin >> c[i];
    }
	fill(dp, dp+x+1, INT_MAX);
	dp[0] = 0;
	for(int i = 0; i < x; i++) {
		if(dp[i] == INT_MAX) continue;
		for(int j = 0; j < n; j++) {
			if(i+c[j] > x) continue;
			dp[i+c[j]] = min(dp[i+c[j]],dp[i]+1);
		}
	}

	cout << (dp[x]==INT_MAX?-1:dp[x]) << endl;


    return 0;
}
