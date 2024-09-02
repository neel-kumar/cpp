#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int main() {
	int n;
	cin >> n;
	int val = n*(n+1) /2;
	if(val%2) {
		cout << 0 << endl;
		return 0;
	}
	val /= 2;

	//int dp[n][val+1] = {0};
	vector<vector<int>> dp(n,vector<int>(val+1,0));
	dp[0][0] = 1;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= val; j++) {
			dp[i][j] = dp[i-1][j];
			if(j-i >= 0) dp[i][j] = (dp[i][j] + dp[i-1][j-i]) %mod;
		}
	}
	cout << dp[n-1][val] << endl;
	return 0;
}
