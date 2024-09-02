#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

const int MOD = 1e9+7;
int n;
vvi go;

vvi mm(vvi g) {
	vvi ret(n, vi(n, 0));
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			ret[i][j] = 0;
			for(int k=0;k<n;k++) {
				ret[i][j] += (g[i][k]*g[k][j]) %MOD;
				ret[i][j] %= MOD;
			}
		}
	}
	return ret;
}

vvi m1(vvi g) {
	vvi ret(n, vi(n, 0));

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			for(int k=0;k<n;k++) {
				ret[i][k] += (g[i][j]*go[j][k]) %MOD;
				ret[i][k] %= MOD;
			}
		}
	}
	return ret;
}

vvi f(vvi g, int k) {
	if(k == 1) return g;
	else if(k%2 == 1) return m1(f(g,k-1));
	else return mm(f(g,k/2));
}

signed main() {
	int k; cin>>n>>k;
	go.resize(n, vi(n));
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>go[i][j];

	vvi ret = f(go, k);
	int ans=0;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) ans = (ans+ret[i][j]) %MOD;
	cout << ans%MOD << endl;
}
