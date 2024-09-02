#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main() {
	int n; cin >> n;
	long long parties[n+1];
	parties[1] = 0;
	for(int i = 2; i <= n; i++) parties[i] = (i * parties[i-1] + (i%2?-1:1))%mod;
	cout << parties[n] << endl;
	return 0;
}
