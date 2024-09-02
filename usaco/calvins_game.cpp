#include <bits/stdc++.h>

using namespace std;

int n, k, memo[2000000], val[2000000], memorev[2000000];

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> val[i];
	memo[k-1] = 0;
	for(int i = 0; i < n; i++) memo[i] = INT_MIN;
	memo[k-1] = 0;
	for(int i = k-1; i < n-1; i++) {
		//cout << memo[i] << " ";
		memo[i+1] = max(memo[i+1], memo[i]+val[i+1]);
		if(i+2 < n) memo[i+2] = memo[i]+val[i+2];
	}
	//cout << memo[n-1] << endl;
	memorev[n-1] = memo[n-1];
	if(n-2 >= 0) memorev[n-2] = INT_MIN;
	for(int i = n-1; i >= 0; i--) {
		memorev[i] = max(memorev[i], memo[i]);
		//cout << memorev[i] << " ";
		if(i-1 >= 0) memorev[i-1] = max(memorev[i-1], memorev[i]+val[i-1]);
		if(i-2 >= 0) memorev[i-2] = memorev[i]+val[i-2];
	}
	//cout << endl;

	int ans = memorev[0];
	// for(int i = 0; i < n; i++) ans = max(ans, memorev[i]);
	cout << ans << endl;

	return 0;
}
