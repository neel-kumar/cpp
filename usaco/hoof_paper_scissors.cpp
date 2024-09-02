#include <bits/stdc++.h>
using namespace std;

int N,K;
int dp[100005][25][3];
int a[100000];

signed main() {
	freopen("hps.in", "r", stdin); freopen("hps.out", "w", stdout);
	cin >> N >> K;
	for(int i=0;i<N;i++) {
		char x; cin >> x;
		if(x == 'H') a[i] = 0;
		else if(x=='P') a[i] = 1;
		else a[i]=2;
	}

	int A=0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<=K;j++) {
			dp[i][j][a[i]]++;
			for(int k = 0; k < 3; k++) {
				A=max(A,dp[i][j][k]);
				dp[i+1][j+1][0] = max(dp[i+1][j+1][0], dp[i][j][k]);
				dp[i+1][j+1][1] = max(dp[i+1][j+1][1], dp[i][j][k]);
				dp[i+1][j+1][2] = max(dp[i+1][j+1][2], dp[i][j][k]);

				dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
			}
		}
	}
	cout << A << endl;
}
