#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int n, k, d;
map<int, int> memo[2];

int rec(int sum, bool has_d) {
	if(sum == n && has_d) return 1;
	if(sum >= n) return 0;
	if(memo[has_d].count(sum)) return memo[has_d][sum];

	int ret = 0;
	for(int i = 1; i <= k; i++) ret = (ret+rec(sum+i, i >= d || has_d))%mod;
	memo[has_d][sum] = ret;
	return ret;
}

int main() {
	cin >> n >> k >> d;
	cout << rec(0, false);
	return 0;
}
